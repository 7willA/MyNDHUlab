pset_time =10
sleep_time = 14
if (pset_time + sleep_time) > 24:
    print("impossible!")
elif (pset_time + sleep_time) >= 24:
    print("full schedule!")
else:
    leftover = abs(24 - pset_time - sleep_time)
    print(leftover, "h of free time!")
print("end of day")