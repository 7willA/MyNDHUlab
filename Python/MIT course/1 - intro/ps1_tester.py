# ps1_tester.py

import put_in_function

def test_part_a():
    test_cases = [
        # (yearly_salary, portion_saved, cost_of_dream_home, expected_months)
        (112000, 0.17, 750000, 97),
        (65000, 0.20, 400000, 79),
        (350000, 0.3, 10000000, 189)
    ]
    
    print("--- Running Test Cases for Part A ---")
    passed = 0
    for i, (salary, saved, home_cost, expected) in enumerate(test_cases, 1):
        result = put_in_function.part_a(salary, saved, home_cost)
        if result == expected:
            print(f"Test Case {i}: PASSED (Expected: {expected}, Got: {result})")
            passed += 1
        else:
            print(f"Test Case {i}: FAILED (Expected: {expected}, Got: {result})")
            
    print(f"\nResult: Passed {passed}/{len(test_cases)} tests.")

if __name__ == "__main__":
    test_part_a()