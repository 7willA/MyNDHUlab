#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>

// Define event types
enum EventType { ARRIVAL, STAFF_AVAILABLE };

// Event structure
struct Event {
    int time;          // Time when the event occurs
    EventType type;    // Type of event
    int data;          // Data: topic_id (for ARRIVAL) or staff_id (for STAFF_AVAILABLE)
    Event(int t, EventType et, int d) : time(t), type(et), data(d) {}
};

// Comparator for the min-heap based on event time
struct EventCompare {
    bool operator()(const Event& e1, const Event& e2) const {
        return e1.time > e2.time; // Smaller time has higher priority
    }
};

// Staff member structure
struct Staff {
    int id;                        // Staff ID
    std::vector<int> priority_list;// List of topics in priority order
    int last_job_start_time;       // Time when their last job started
    int input_order;               // Order in which the staff member was listed in input
};

int main() {
    int scenario_num = 1;
    while (true) {
        int num_topics;
        std::cin >> num_topics;
        if (num_topics == 0) break; // End of all scenarios

        // Maps topic_id -> service time, and topic_id -> number of waiting requests
        std::unordered_map<int,int> service_times, waiting_requests;
        // Priority queue of events
        std::priority_queue<Event, std::vector<Event>, EventCompare> event_queue;
        // List of all staff members
        std::vector<Staff> staff_list;
        // Set of currently available staff IDs
        std::set<int> available_staff;
        int max_finish_time = 0;

        // Read topic information and enqueue ARRIVAL events
        for (int i = 0; i < num_topics; ++i) {
            int topic_id, num_requests, first_arrival, service_time, time_between;
            std::cin >> topic_id >> num_requests >> first_arrival >> service_time >> time_between;
            service_times[topic_id] = service_time;
            waiting_requests[topic_id] = 0;
            int t = first_arrival;
            for (int j = 0; j < num_requests; ++j) {
                event_queue.push(Event(t, ARRIVAL, topic_id));
                t += time_between;
            }
        }

        // Read staff information and enqueue initial STAFF_AVAILABLE events at time 0
        int num_personnel;
        std::cin >> num_personnel;
        for (int i = 0; i < num_personnel; ++i) {
            int staff_id, num_topics_staff;
            std::cin >> staff_id >> num_topics_staff;
            std::vector<int> plist(num_topics_staff);
            for (int j = 0; j < num_topics_staff; ++j) {
                std::cin >> plist[j];
            }
            // Initialize last_job_start_time to 0 (opening time)
            staff_list.push_back({staff_id, plist, 0, i});
            event_queue.push(Event(0, STAFF_AVAILABLE, staff_id));
        }

        // Comparator for available staff selection
        auto cmp_staff = [](const Staff* a, const Staff* b) {
            if (a->last_job_start_time != b->last_job_start_time)
                return a->last_job_start_time < b->last_job_start_time;
            return a->input_order < b->input_order;
        };

        // Simulation loop
        while (!event_queue.empty()) {
            int current_time = event_queue.top().time;

            // 1) Process all events occurring at current_time
            while (!event_queue.empty() && event_queue.top().time == current_time) {
                Event ev = event_queue.top();
                event_queue.pop();
                if (ev.type == ARRIVAL) {
                    waiting_requests[ev.data]++;
                } else { // STAFF_AVAILABLE
                    available_staff.insert(ev.data);
                }
            }

            // 2) Assign available staff to waiting requests as long as possible
            bool assigned_any = true;
            while (assigned_any && !available_staff.empty()) {
                assigned_any = false;
                // Gather all currently free staff members
                std::vector<Staff*> candidates;
                for (auto& s : staff_list) {
                    if (available_staff.count(s.id)) {
                        candidates.push_back(&s);
                    }
                }
                // Sort by earliest last job start time, then by input order
                std::sort(candidates.begin(), candidates.end(), cmp_staff);

                // Try to assign each staff in order
                for (Staff* s : candidates) {
                    for (int topic : s->priority_list) {
                        if (waiting_requests[topic] > 0) {
                            // Assign the request
                            waiting_requests[topic]--;
                            int finish = current_time + service_times[topic];
                            max_finish_time = std::max(max_finish_time, finish);
                            s->last_job_start_time = current_time;
                            // Enqueue when this staff becomes free again
                            event_queue.push(Event(finish, STAFF_AVAILABLE, s->id));
                            available_staff.erase(s->id);
                            assigned_any = true;
                            break;
                        }
                    }
                    if (assigned_any) break;
                }
            }
        }

        // Output result for this scenario
        std::cout << "Scenario " << scenario_num
                  << ": All requests are serviced within "
                  << max_finish_time << " minutes." << std::endl;
        scenario_num++;
    }
    return 0;
}
