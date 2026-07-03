All funtions working
No safety mechanism yet, Mayabag siyag di mao na info imo e feed.

[done] 		Add new student — Let Dr. Santos enter a new student (ID, name, major, GPA, credits)
[done?] 	Student data storage — Hold information for up to 10 students
[done]		Search by ID — Find a student and display all their information
[done]		Search by GPA — Find all students with GPA above a threshold
[done]		Search by major — Find all students in a specific major with a count
[done]		Display all students — Show all entered students in an organized, readable format


My process explanation:

To process student data, I keep all the information for one person at the same position across several lists
(like ang id/name sa student no.1 kai naas index 0, so iyang ubang info kai naa rapuds index 0 sa ubang arrays), so the 
data stays linked When I add a student, I simply put their details into the first empty spot and increase my counter. 
Searching is equally straightforward: I use a loop to walk through my lists starting from the beginning, checking each 
student one at a time. If a student's info matches what I am looking for, I flag them and print their details; if I reach 
the end of my counter and find nothing, I tell the user that no matches exist. This "check every row" process ensures that 
I never miss a match and keeps my logic simple and reliable. By separating the adding, searching, and displaying into their 
own steps, the program acts as a pipeline where each part of the process only handles its specific job. This keeps the flow 
clean and makes it easy to fix bugs, as I always know exactly which step of the process is responsible for the data I am 
currently handling.
