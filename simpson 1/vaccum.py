location = input("Enter location (A/B): ")
status = input("Enter status (D=Dirty, C=Clean): ")

if status == 'D':
    print("Action: Suck")
elif location == 'A':
    print("Action: Move Right")
else:
    print("Action: Move Left")