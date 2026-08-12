# put_in_function.py

def part_a(yearly_salary, portion_saved, cost_of_dream_home):
    portion_down_payment = 0.25
    cost_of_down_payment = cost_of_dream_home * portion_down_payment
    amount_saved = 0.0
    r = 0.05
    months = 0

    while amount_saved < cost_of_down_payment:
        monthly_return = amount_saved * (r / 12)
        monthly_deposit = (yearly_salary / 12) * portion_saved
        amount_saved += monthly_return + monthly_deposit
        months += 1

    return months