All funtions working
safety mechanism Works
[done] 		Add new student — Let Dr. Santos enter a new student (ID, name, major, GPA, credits) 
[done?] 	Student data storage — Hold information for up to 10 students
[done]		Search by ID — Find a student and display all their information
[done]		Search by GPA — Find all students with GPA above a threshold
[done]		Search by major — Find all students in a specific major with a count
[done]		Display all students — Show all entered students in an organized, readable format


My process explanation:

To process student data, I use a structure (STUDENT) that groups all information about one person, such as their
ID number, name, major, GPA, and credits, into a single record. Instead of storing each piece of information in separate arrays,
all details of one student are kept together at the same index of the structure array. For example, student[0] contains the complete
information of the first student, including their ID, name, major, GPA, and credits. When adding a student, the program stores their 
information in the next available position in the structure array and then increases the student counter to keep track of how many 
records are currently stored. Searching works by looping through the structure array from the beginning up to the current counter value. 
Each student's stored information is compared with the user's search criteria, such as ID number, GPA threshold, or major. If a matching 
record is found, the program displays that student's complete information. If the loop finishes without finding any match, the program 
informs the user that no matching student exists. By separating the adding, searching, and displaying operations into their own functions, 
each part of the program handles a specific task. This creates a cleaner and more organized process, making the program easier to understand, 
debug, and maintain because all student-related data is managed through a single structure format.



