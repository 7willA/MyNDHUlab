
yearly_salary = float(input("Enter your yearly salary: "))

portion_saved = float (input("Enter the percent of your salary to save, as a decimal: "))

cost_of_dream_home =float(input("Enter the cost of your dream home: "))

portion_down_payment = 0.25
r = 0.05
amount_saved = 0.0
months = 0

down_payment = cost_of_dream_home * portion_down_payment
monthly_salary = yearly_salary / 12

while amount_saved < down_payment: 
    monthly_return = amount_saved * (r / 12)

    monthly_savings = monthly_salary * portion_saved

    
    amount_saved = monthly_return + monthly_savings + amount_saved
    
    
    months = months + 1

print("Number of months: ", months)