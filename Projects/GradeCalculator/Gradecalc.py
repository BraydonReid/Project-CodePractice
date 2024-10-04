def gradeCalc(x, Grading):
    GradeCalculator = Grading
    Names = list(x.keys())  
    Grades = list(x.values())  

    # Sorting Homework 
    if len(Grades[0]) >= 6:
        Grades[0].sort(reverse=True)
        Grades[0] = Grades[0][:6]
    else:
        while len(Grades[0]) < 6:
            Grades[0].append(0)  

    # Sorting Labs 
    if len(Grades[1]) >= 8:
        Grades[1].sort(reverse=True)
        Grades[1] = Grades[1][:8]
    else:
        while len(Grades[1]) < 8:
            Grades[1].append(0)  

    # Calculate the average grades
    Grades_N_Tot = []
    for i in range(len(Names)):
        Grades_N_Tot.append(round(sum(Grades[i]) / len(Grades[i])))

    GradeTotal = dict(zip(Names, Grades_N_Tot))

    # Calculate total grade
    summ = 0
    for i in Names:
        summ += (GradeTotal[i] * GradeCalculator[i]) / 100

    GradeTotal.update({'Total Grade': round(summ, 2)})

    # Determine letter grade
    if summ > 89.5:
        GradeTotal.update({'LetterGrade': 'A'})
    elif summ > 79.5:
        GradeTotal.update({'LetterGrade': 'B'})
    elif summ > 69.5:
        GradeTotal.update({'LetterGrade': 'C'})
    elif summ > 59.5:
        GradeTotal.update({'LetterGrade': 'D'})
    else:
        GradeTotal.update({'LetterGrade': 'F'})

    return GradeTotal


# main
with open("Grades.txt", "w") as file:
    while True:

        studentName = input("Please Enter the Student's Name: ")
        StudentID = input("Please Enter the Student ID: ")

        HomeWork = list(map(int, input("Please Enter the Homework Grades (separated by commas): ").split(",")))
        Labs = list(map(int, input("Please Enter the Lab Grades (separated by commas): ").split(",")))
        MidTerm = [int(input("Please Enter the MidTerm Score: "))]
        Final = [int(input("Please Enter the Final Score: "))]
        FinalProject = [int(input("Please Enter the Final Project Score: "))]

        table = ["HomeWork", "Labs", "MidTerm", "Final", "FinalProject"]
        Info = [HomeWork, Labs, MidTerm, Final, FinalProject]

        StudentInfo = dict(zip(table, Info))

        GradeScale = {'HomeWork': 20, 'Labs': 30, 'MidTerm': 20, 'Final': 20, 'FinalProject': 10}

        finalGrade = gradeCalc(StudentInfo, GradeScale)

        file.write(f"Name: {studentName}\n")
        file.write(f"Number: {StudentID}\n")
        file.write(f"HW: {','.join(map(str, HomeWork))}\n")
        file.write(f"Labs: {','.join(map(str, Labs))}\n")
        file.write(f"MidTerm Exam: {','.join(map(str, MidTerm))}\n")
        file.write(f"Final Exam: {','.join(map(str, Final))}\n")
        file.write(f"Final Project: {','.join(map(str, FinalProject))}\n")
        file.write(f"Overall Grade: {finalGrade['Total Grade']}\n")
        file.write(f"Overall Letter Grade: {finalGrade['LetterGrade']}\n")



        cont = int(input("Press 1 to add more students or 0 to exit: "))
        if cont not in [0, 1]:
            print("Invalid Input! ... Exiting")
            break
        elif cont == 0:
            break

