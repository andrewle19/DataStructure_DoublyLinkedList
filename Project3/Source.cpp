// Project 3
// Andrew Le
// andrewle19@csu.fullerton.edu


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// doubley linked list
class List
{
private:
	// student object node struct
	struct student{
		string intials; // intials of student
		string name; // student name 
		bool seat; // in seat
		int seatnumber; // student's seat number
		bool inclass; // in the class physically
		bool attendance; // did the student attend class if class is true or seat is true
		int team; // team assignment
		int pair; // pair of student
		string major; // major of student
		student *next; // node next pointer
		student *prev; // node previous pointer

	};
	student* head; // head of list
	student* temp; // temp node
	student* tail; // tail pontinter
public:
	// default constuctor
	List()
	{
		head = NULL;
		tail = NULL;
		temp = NULL;
	}

	// Fill Student ClassRoom 
	// parameter list: studetn name, student intials, is student in class, is student in seat, student seat number,student attendance, team number,pair number , major
	void FillStudentClassroom(string my_name, string my_intials, bool my_class, bool my_seat, int seatnumber, bool attendance, int my_team, int my_pair, string my_major)
	{
		student* n = new student; // create new node student pointer
		n->next = NULL; // make it point to Null this will put node at the end of the list
		n->prev = NULL; // make previous point to null;
		// add data to story
		n->name = my_name;
		n->intials = my_intials;
		n->seatnumber = seatnumber;
		n->seat = my_seat;
		n->attendance = attendance;
		n->inclass = my_class;
		n->team = my_team;
		n->pair = my_pair;
		n->major = my_major;


		if (head != NULL) // if the head already exists
		{
			tail->next = n; // tail will will be at the end so insert the new node after the tail
			n->prev = tail; // make the new node prev point to the old tail
			tail = n; // make new node the tail
		}
		else // if list is not made
		{
			head = n; // head will equal new node
			tail = n; // tail will equal new node
		}
	}

	// Print List Forward
	// Displays list using the next node till gets to the end starting at head
	void PrintForward()
	{
		temp = head; // starts at the front of the list
		cout << '\n';
		cout << "Classroom List" << endl;
		while (temp != NULL)
		{
			cout << "Student Name: " << temp->name << endl;
			cout << "Student Intial: " << temp->intials << endl;
			// print out attendance
			if (temp->attendance == true)
			{
				cout << "Student Attendance: Present" << endl;
			}
			else
			{
				cout << "Student Attendance: Absent" << endl;
			}
			// print out if he/she is physically in class
			if (temp->inclass == true)
			{
				cout << "Student is in class" << endl;
			}
			else
			{
				cout << "Student is not in class" << endl;
			}

			// print out if he/she is in their seat
			if (temp->seat == true)
			{
				cout << "Student is in seat" << endl;
			}
			else
			{
				cout << "Student is not in seat" << endl;
			}
			cout << "SeatNumber: " << temp->seatnumber << endl;
			//print out team 
			// if team is 0 student has no team
			if (temp->team == 0)
			{
				cout << "Team Number: No Team " << endl;
			}
			else
			{
				cout << "Team Number: " << temp->team << endl;
			}

			cout << "Pair Number: " << temp->pair << endl;
			cout << "Major: " << temp->major << endl;
			cout << '\n';
			temp = temp->next; // advances the list
		}
	}

	// Print Backwards
	// Displays list starting from the end the tail to the beggining the head
	void PrintBack()
	{
		temp = tail; // starts at the back of the list
		cout << '\n';
		cout << "Classroom List" << endl;
		while (temp != NULL)
		{

			cout << "Student Name: " << temp->name << endl;
			cout << "Student Intial: " << temp->intials << endl;
			if (temp->attendance == true)
			{
				cout << "Student Attendance: Present" << endl;
			}
			else
			{
				cout << "Student Attendance: Absent" << endl;
			}

			if (temp->seat == true)
			{
				cout << "Student is in seat" << endl;
			}
			else
			{
				cout << "Student is not in seat" << endl;
			}
			cout << "SeatNumber: " << temp->seatnumber << endl;
			//print out team 
			// if team is 0 student has no team
			if (temp->team == 0)
			{
				cout << "Team Number: No Team " << endl;
			}
			else
			{
				cout << "Team Number: " << temp->team << endl;
			}

			cout << "Pair Number: " << temp->pair << endl;
			cout << "Major: " << temp->major << endl;
			cout << '\n';
			temp = temp->prev; // advances the list
		}
	}

	// Inset Student
	// Insets a student to the front of the list
	// parameter list: studetn name, student intials, is student in class, is student in seat,student attendance, team number,pair number , major
	void AddStudent(string my_name, string my_intials, bool my_class, int seatnumber, bool my_seat, bool attendance, int my_team, int my_pair, string my_major)
	{
		student* n = new student; // create new node student pointer
		n->next = NULL; // make it point to Null this will put node at the end of the list
		n->prev = NULL; // make previous point to null;
		// add data to story
		n->name = my_name;
		n->intials = my_intials;
		n->seat = my_seat;
		n->seatnumber = seatnumber;
		n->attendance = attendance;
		n->inclass = my_class;
		n->team = my_team;
		n->pair = my_pair;
		n->major = my_major;

		if (head != NULL) // if the head already exists
		{
			n->next = head; // makes the pointer of new node the old head
			head->prev = n; // head prev points to new node(new head
			head = n; // new node becomes the head
		}
		else // if there is no list
		{
			head = n; // n is the head
			tail = n; // n is the tail
		}


	}

	// Find Student
	// Searches to see if student is there
	// parameter list: student name
	void FindStudent()
	{
		string name; // if user wants to search by name
		string intial;  // if user wants to search by intial
		int seatnumber; // if user wants to search by seat number
		int team; // if user wants to search by team number
		string major; // if user wants to search by major
		int choice; // choice the user will make
		bool valid = false; // to check if user is valid
		bool found = false; // if student found or not
		temp = head; // set temp to head of the list
		
		while (valid == false)
		{
			cout << "How do you want to Search for the Student(1-5)?" << endl;
			cout << "1: Name " << endl;
			cout << "2: Intials " << endl;
			cout << "3: Seat Number " << endl;
			cout << "4: Team Number(0-4) " << endl;
			cout << "5: Major" << endl;
			cin >> choice; // grab user choice
			
			if (choice == 1) // if user wants to search by name
			{
				cout << "What is the Student's Name " << endl; // get user input
				cin.ignore();
				getline(cin, name);

				while (temp != NULL) // until list is over or found the student
				{

					if (temp->name == name) // if student is found
					{
						found = true; // student was found 
						cout << "Student " << name << " was found " << endl;

						// print out whoever you found
						cout << "Student Name: " << temp->name << endl;
						cout << "Student Intial: " << temp->intials << endl;
						cout << "Student Seat Number: " << temp->seatnumber << endl;
						if (temp->inclass == true)
						{
							cout << "Student is in class" << endl;
						}
						else
						{
							cout << "Student is not in class" << endl;
						}

						if (temp->seat == true)
						{
							cout << "Student is in seat" << endl;
						}
						else
						{
							cout << "Student is not in seat" << endl;
						}


						if (temp->attendance == true)
						{
							cout << "Student Attendance: Present" << endl;
						}
						else
						{
							cout << "Student Attendance: Absent" << endl;
						}

						//print out team 
						// if team is 0 student has no team
						if (temp->team == 0)
						{
							cout << "Team Number: No Team " << endl;
						}
						else
						{
							cout << "Team Number: " << temp->team << endl;
						}
						cout << "Pair Number: " << temp->pair << endl;
						cout << "Major: " << temp->major << endl;
						cout << '\n';


					}
					temp = temp->next; // traverse the list
				}
				valid = true; // end loop
			}
			else if (choice == 2) // if user wants to search by intials
			{
				cout << "What is the Student's Intials" << endl; // get user input
				cin.ignore();
				getline(cin, intial);
				
				while (temp != NULL) // until list is over or found the student
				{

					if (temp->intials == intial) // if student is found
					{
						found = true; // student was found 
						cout << "Student " << intial << " was found " << endl;

						// print out whoever you found
						cout << "Student Name: " << temp->name << endl;
						cout << "Student Intial: " << temp->intials << endl;
						cout << "Student Seat Number: " << temp->seatnumber << endl;
						if (temp->inclass == true)
						{
							cout << "Student is in class" << endl;
						}
						else
						{
							cout << "Student is not in class" << endl;
						}

						if (temp->seat == true)
						{
							cout << "Student is in seat" << endl;
						}
						else
						{
							cout << "Student is not in seat" << endl;
						}


						if (temp->attendance == true)
						{
							cout << "Student Attendance: Present" << endl;
						}
						else
						{
							cout << "Student Attendance: Absent" << endl;
						}

						//print out team 
						// if team is 0 student has no team
						if (temp->team == 0)
						{
							cout << "Team Number: No Team " << endl;
						}
						else
						{
							cout << "Team Number: " << temp->team << endl;
						}
						cout << "Pair Number: " << temp->pair << endl;
						cout << "Major: " << temp->major << endl;
						cout << '\n';


					}
					temp = temp->next; // traverse the list
				}
				valid = true; // end loop
			}
			else if (choice == 3) // if user wants Seat number
			{
				cout << "What is the Seat Number:" << endl; // get user input on seat number
				cin >> seatnumber;

				while (temp != NULL) // until list is over or found the student
				{

					if (temp->seatnumber ==	 seatnumber) // if student is found
					{
						found = true; // student was found 
						cout << "Student " << "was found in seat: " << seatnumber  << endl;

						// print out whoever you found
						cout << "Student Name: " << temp->name << endl;
						cout << "Student Intial: " << temp->intials << endl;
						cout << "Student Seat Number: " << temp->seatnumber << endl;
						if (temp->inclass == true)
						{
							cout << "Student is in class" << endl;
						}
						else
						{
							cout << "Student is not in class" << endl;
						}

						if (temp->seat == true)
						{
							cout << "Student is in seat" << endl;
						}
						else
						{
							cout << "Student is not in seat" << endl;
						}


						if (temp->attendance == true)
						{
							cout << "Student Attendance: Present" << endl;
						}
						else
						{
							cout << "Student Attendance: Absent" << endl;
						}

						//print out team 
						// if team is 0 student has no team
						if (temp->team == 0)
						{
							cout << "Team Number: No Team " << endl;
						}
						else
						{
							cout << "Team Number: " << temp->team << endl;
						}
						cout << "Pair Number: " << temp->pair << endl;
						cout << "Major: " << temp->major << endl;
						cout << '\n';


					}
					temp = temp->next; // traverse the list
				}
				valid = true; // end loop
			}
			else if (choice == 4) // if user wants team number
			{
				cout << "What is the Team Number(0-4)" << endl; // get user input on seat number
				cin >> team;

				while (temp != NULL) // until list is over or found the student
				{

					if (temp->team == team) // if student is found
					{
						found = true; // student was found 
						cout << "Student or Students found in team: " << team << endl;

						// print out whoever you found
						cout << "Student Name: " << temp->name << endl;
						cout << "Student Intial: " << temp->intials << endl;
						cout << "Student Seat Number: " << temp->seatnumber << endl;
						if (temp->inclass == true)
						{
							cout << "Student is in class" << endl;
						}
						else
						{
							cout << "Student is not in class" << endl;
						}

						if (temp->seat == true)
						{
							cout << "Student is in seat" << endl;
						}
						else
						{
							cout << "Student is not in seat" << endl;
						}


						if (temp->attendance == true)
						{
							cout << "Student Attendance: Present" << endl;
						}
						else
						{
							cout << "Student Attendance: Absent" << endl;
						}

						//print out team 
						// if team is 0 student has no team
						if (temp->team == 0)
						{
							cout << "Team Number: No Team " << endl;
						}
						else
						{
							cout << "Team Number: " << temp->team << endl;
						}
						cout << "Pair Number: " << temp->pair << endl;
						cout << "Major: " << temp->major << endl;
						cout << '\n';


					}
					temp = temp->next; // traverse the list
				}
				valid = true; // end loop
			}
			else if (choice == 5) // if user wants team number
			{
				cout << "What is the Student's Major?" << endl; // get user input on Major
				cin.ignore();
				getline(cin, major);

				while (temp != NULL) // until list is over or found the student
				{

					if (temp->major == major) // if student is found
					{
						found = true; // student was found 
						cout << "Student or Students with the Major:  " << major << endl;

						// print out whoever you found
						cout << "Student Name: " << temp->name << endl;
						cout << "Student Intial: " << temp->intials << endl;
						cout << "Student Seat Number: " << temp->seatnumber << endl;
						if (temp->inclass == true)
						{
							cout << "Student is in class" << endl;
						}
						else
						{
							cout << "Student is not in class" << endl;
						}

						if (temp->seat == true)
						{
							cout << "Student is in seat" << endl;
						}
						else
						{
							cout << "Student is not in seat" << endl;
						}


						if (temp->attendance == true)
						{
							cout << "Student Attendance: Present" << endl;
						}
						else
						{
							cout << "Student Attendance: Absent" << endl;
						}

						//print out team 
						// if team is 0 student has no team
						if (temp->team == 0)
						{
							cout << "Team Number: No Team " << endl;
						}
						else
						{
							cout << "Team Number: " << temp->team << endl;
						}
						cout << "Pair Number: " << temp->pair << endl;
						cout << "Major: " << temp->major << endl;
						cout << '\n';


					}
					temp = temp->next; // traverse the list
				}
				valid = true; // end loop
			}
			else
			{
				cout << "Invalid Input Try Again" << endl;
			}
		}


		// student was not found
		if (found == false)
		{
			cout << "Student was not found " << endl;
		}
		cout << '\n';
	}

	//Remove Student
	// Search for student first then remove him/her
	// parameter list:Student name
	void RemoveStudent(string name)
	{
		bool found = false; // if student found or not
		temp = head; // set temp to head of the list

		student* delptr = NULL; // deleteing a ptr

		while (temp != NULL)
		{
			if (temp->name == name) // if student is found
			{
				found = true; // student was found 
				delptr = temp; // delete temp
				// first check if the node is the only node in list
				if (delptr == head && delptr == tail)
				{
					head = NULL;
					tail = NULL;
					cout << "Student " << name << " removed from class list" << endl;
				}
				// if node isnt alone
				else{
					// if student deleted is the head
					if (delptr == head)
					{
						head = temp->next; // head will be the next node
						head->prev = NULL; // new head prev will be null 

						cout << "Student " << name << " removed from class list" << endl;
					}
					// if student found at the head
					else if (delptr == tail)
					{
						tail = temp->prev; // tail will be the previous node
						tail->next = NULL; // previous node will point to node

						cout << "Student " << name << " removed from class list" << endl;
					}
					// if student not found in head or tail but found in list
					else
					{
						temp->prev->next = temp->next; // the node before temp next pointer will point the node after temp
						temp->next->prev = temp->prev; // the node after temp prev pointer will point to the node befroe temp
						delptr = temp; // delete the student
						cout << "Student " << name << " removed from class list" << endl;
					}
				}
			}

			temp = temp->next; // traverse the list
		}


		if (found == false) // student is not found
		{
			cout << "Student " << name << " was not found " << endl;
		}
		delete delptr;

		cout << '\n';
	}

	// Assign Student to team
	// Search for student by name then assigns them to a team
	// parameter list: Student name
	void AssignTeam(string name)
	{
		bool found = false; // if student found or not
		temp = head; // set temp to head of the list
		int team; // team number variable
		while (temp != NULL)
		{
			if (temp->name == name) // if student is found
			{
				found = true;
				cout << "Assign Student to Team(0-4): " << endl;
				cin >> team; // asigns number to variable
				temp->team = team; // change students team

				// print out whoever u changed
				cout << "Student Name: " << temp->name << endl;
				cout << "Student Intial: " << temp->intials << endl;
				cout << "Student seat number: " << temp->seatnumber << endl;
				if (temp->inclass == true)
				{
					cout << "Student is in class" << endl;
				}
				else
				{
					cout << "Student is not in class" << endl;
				}

				if (temp->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}


				if (temp->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}

				//print out team 
				// if team is 0 student has no team
				if (temp->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else{
					cout << "Team Number: " << temp->team << endl;
				}
				cout << "Pair Number: " << temp->pair << endl;
				cout << "Major: " << temp->major << endl;
				cout << '\n';


			}
			temp = temp->next; // traverse the list
		}



		if (found == false) // student is not found
		{
			cout << "Student " << name << " was not found " << endl;
		}
		cout << '\n';
	}

	// Replace student with another new student
	// Search for student by intial then assign new values to the student
	// parameter list : Student intial
	void ReplaceStudent(string intial)
	{
		bool found = false; // if student found or not
		temp = head; // set temp to head of the list
		string newname; // new name of student
		string newintials; // new intials of student
		bool inclass; // if he is in class
		bool newseat; // if he is in his seat
		int seatnumber; // his seat number
		bool validclass = false; // checks if class awnser is valid
		bool validseat = false; // checks if seat awnser is valid
		bool attendance; // if student attended class
		string yesorno; // takes user awnser of yes or no
		int newteam;
		int newpair;
		string newmajor;

		while (temp != NULL)
		{
			if (temp->intials == intial) // if student is found
			{
				found = true;

				// Asks the user for the new student info to replace old student
				cout << "What is new Student's name?: " << endl;
				cin.ignore();
				getline(cin, newname);
				cout << "What is the Student's intials?: " << endl;
				cin >> newintials;
				//Asks for seat number
				cout << "What is the Students seat number: " << endl;
				cin >> seatnumber;
				// ask if user is in class or not 
				while (validclass == false) // checks if awnser is valid
				{
					cout << "Is the Student in class(yes/no)? " << endl;
					cin >> yesorno;

					if (yesorno == "yes")
					{
						validclass = true;
						inclass = true;

						// ask if student is in his seat or not( has to be in class to be in seat
						while (validseat == false)  // checks if awnser is valid
						{
							cout << "Is the Student in his/her seat(yes/no)? " << endl;
							cin >> yesorno;

							if (yesorno == "yes")
							{
								validseat = true;
								newseat = true;
							}
							else if (yesorno == "no")
							{
								validseat = true;
								newseat = false;
							}
							else
							{
								cout << "Not Valid Choice" << endl;
							}
						}
					}
					// student not in class also not in seat
					else if (yesorno == "no")
					{
						validclass = true;
						inclass = false;
						newseat = false; // cant be in seat if not in class


					}
					else
					{
						cout << "Not Valid Choice" << endl;
					}
					// check if student attended class
					if (inclass == true)
					{
						attendance = true;
					}
					else
					{
						attendance = false;
					}
					cout << "What is the Student's Team(0-4):" << endl;
					cin >> newteam;
					cout << "What is the Student's Pair: " << endl;
					cin >> newpair;
					cout << "What is the Student's Major: " << endl;
					cin.ignore();
					getline(cin, newmajor);

					// Replace student data
					temp->name = newname;
					temp->intials = newintials;
					temp->inclass = inclass;
					temp->seatnumber = seatnumber;
					temp->seat = newseat;
					temp->attendance = attendance;
					temp->team = newteam;
					temp->pair = newpair;
					temp->major = newmajor;

					//Print out New Student that replaced the old one
					cout << "Student " << intial << " Replaced by New Student " << endl;
					cout << "Student Name: " << temp->name << endl;
					cout << "Student Intial: " << temp->intials << endl;
					if (temp->attendance == true)
					{
						cout << "Student Attendance: Present" << endl;
					}
					else
					{
						cout << "Student Attendance: Absent" << endl;
					}

					if (temp->seat == true)
					{
						cout << "Student is in seat" << endl;
					}
					else
					{
						cout << "Student is not in seat" << endl;
					}
					cout << "SeatNumber: " << temp->seatnumber << endl;
					//print out team 
					// if team is 0 student has no team
					if (temp->team == 0)
					{
						cout << "Team Number: No Team " << endl;
					}
					else
					{
						cout << "Team Number: " << temp->team << endl;
					}
					cout << "Pair Number: " << temp->pair << endl;
					cout << "Major: " << temp->major << endl;
					cout << '\n';
				}


			}
			temp = temp->next; // traverse the list
		}



		if (found == false) // student is not found
		{
			cout << "Student " << intial << " was not found " << endl;
		}
		cout << '\n';
	}

	// Display Students in certain team
	//  Find and Print all Students in a certain team
	// Search for Students by team then output all in that team
	// parameter list: team number

	void DisplayStudentTeam(int team)
	{
		bool found = false; // found or not
		temp = head; // start at head
		cout << '\n';
		if (team == 0) // if team is 0 means unAssignened team
		{
			cout << "Unassigned Team Students " << endl;
		}
		else
		{
			cout << "Team " << team << " Students" << endl;
		}

		while (temp != NULL) // till the end of the list
		{
			if (temp->team == team) // if student in team is found print student
			{
				cout << "Student Name: " << temp->name << endl;
				cout << "Student Intial: " << temp->intials << endl;



				if (temp->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}

				if (temp->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}
				cout << "SeatNumber: " << temp->seatnumber << endl;
				//print out team 
				// if team is 0 student has no team
				if (temp->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << temp->team << endl;
				}

				cout << "Pair Number: " << temp->pair << endl;
				cout << "Major: " << temp->major << endl;
				cout << '\n';
				found = true;
			}
			temp = temp->next;
		}
		if (found == false)
		{
			cout << "No Students found in this Team " << endl;
		}
	}

	// Order Students by Team
	// Traverse list then for each team then any student associated with that team
	
	void OrderTeam()
	{
		temp = head; // start at the head of the list
		int teamnumber = 1; // look for this int team number then print
		// Traverse list printing out the students by team
		cout << '\n';
		
		while (teamnumber < 5) // for how many stories their are
		{
			cout << "Team " << teamnumber << " Students " << endl;
			while (temp != NULL)
			{
				if (temp->team == teamnumber) // if team member found print it out
				{
					cout << "Student Name: " << temp->name << endl;
					cout << "Student Intial: " << temp->intials << endl;
					// print out attendance
					if (temp->attendance == true)
					{
						cout << "Student Attendance: Present" << endl;
					}
					else
					{
						cout << "Student Attendance: Absent" << endl;
					}
					// print out if he/she is physically in class
					if (temp->inclass == true)
					{
						cout << "Student is in class" << endl;
					}
					else
					{
						cout << "Student is not in class" << endl;
					}

					// print out if he/she is in their seat
					if (temp->seat == true)
					{
						cout << "Student is in seat" << endl;
					}
					else
					{
						cout << "Student is not in seat" << endl;
					}
					cout << "SeatNumber: " << temp->seatnumber << endl;
					//print out team 
					// if team is 0 student has no team
					if (temp->team == 0)
					{
						cout << "Team Number: No Team " << endl;
					}
					else
					{
						cout << "Team Number: " << temp->team << endl;
					}

					cout << "Pair Number: " << temp->pair << endl;
					cout << "Major: " << temp->major << endl;
					cout << '\n';
				}
				temp = temp->next; // advances the list

			}
			teamnumber++;
			temp = head; // go bad to the head then look again
		}
		
		// Print out Unassigned Students
		cout << "Unassigned Team Students" << endl;
		while (temp != NULL)
		{
			if (temp->team == 0) // if u find Students without a team
			{
				cout << "Student Name: " << temp->name << endl;
				cout << "Student Intial: " << temp->intials << endl;
				// print out attendance
				if (temp->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}
				// print out if he/she is physically in class
				if (temp->inclass == true)
				{
					cout << "Student is in class" << endl;
				}
				else
				{
					cout << "Student is not in class" << endl;
				}

				// print out if he/she is in their seat
				if (temp->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}
				cout << "SeatNumber: " << temp->seatnumber << endl;
				//print out team 
				// if team is 0 student has no team
				if (temp->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << temp->team << endl;
				}

				cout << "Pair Number: " << temp->pair << endl;
				cout << "Major: " << temp->major << endl;
				cout << '\n';
			}
			temp = temp->next; // traverse the list
		}
	}

	// Mark whether student is absent or not plus marks if they are physically in class or not plus seat
	// searches for name then asks user if the student is absent will display change after
	// parameter list student name
	void MarkAbsent(string name)
	{
		bool found = false; // if student found or not
		temp = head; // set temp to head of the list
		bool attendance; // if student attending
		bool inclass; // is he/she in class physically
		bool inseat; // is he/she in seat
		bool valid = false; // check if user choice is valid
		bool valid2 = false; // check if user choice second awnser is valid
		bool valid3 = false; // check 
		string yesorno; // user will type yes or no
		string choice; // user type yes or no for choice
		string choice2; // user types yes or no to choice
		while (temp != NULL)
		{
			if (temp->name == name) // if student is found
			{
				found = true;

				while (valid == false)
				{
					cout << "Is the Student Absent(yes/no)? " << endl;
					cin >> yesorno; // asigns number to variable

					if (yesorno == "no") // Student Attended Class but is he physically in class or in his seat
					{
						attendance = true;
						while (valid2 == false)
						{
							cout << "Is the Student in Class Physically(yes/no)? " << endl;
							cin >> choice;
							if (choice == "yes") // student is physically in seat
							{
								inclass = true;
								// then ask if the student is in his or her desk
								while (valid3 == false)
								{
									cout << "Is the Student seated(yes/no)" << endl;
									cin >> choice2;
									if (choice2 == "yes") // student is seated
									{
										inseat = true;
										valid3 = true;
									}
									else if (choice2 == "no") // student is not siting
									{
										inseat = false;
										valid3 = true;
									}
									else
									{
										cout << "Invalid Input Try Again " << endl;
									}

									valid2 = true;
								}

							}
							else if (choice == "no") // Student is present but not in class or in seat
							{
								cout << "Student Attended Class but is not in class" << endl;
								inclass = false;
								inseat = false;
								valid2 = true;
							}
							else
							{
								cout << "Invalid Input Try Again " << endl;
							}
						}

						valid = true;
					}
					else if (yesorno == "yes") // student is absent therefore not in seat or in class
					{
						attendance = false;
						inclass = false;
						inseat = false;
						valid = true;
					}
					else
					{
						cout << "Invalid Input Try Again " << endl;
					}

				}
				temp->attendance = attendance; // change students attendance 
				temp->inclass = inclass; // change student physically in class
				temp->seat = inseat; // change student seat

				// print out whoever u changed
				cout << '\n';
				cout << "Student Name: " << temp->name << endl;
				cout << "Student Intial: " << temp->intials << endl;
				cout << "Student seat number: " << temp->seatnumber << endl;
				if (temp->inclass == true)
				{
					cout << "Student is in class" << endl;
				}
				else
				{
					cout << "Student is not in class" << endl;
				}

				if (temp->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}


				if (temp->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}

				//print out team 
				// if team is 0 student has no team
				if (temp->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << temp->team << endl;
				}
				cout << "Pair Number: " << temp->pair << endl;
				cout << "Major: " << temp->major << endl;
				cout << '\n';

			}
			temp = temp->next; // traverse the list
		}
		if (found == false) // if student is not found
		{
			cout << "Student " << name << " not found" << endl;
		}
	}

	// Display Absent Students
	// Searches list for Absent Students then prints them
	void DisplayAbsent()
	{
		temp = head; // start at head
		bool found = false;
		cout << "Absent Students " << endl;
		while (temp != NULL)
		{
			if (temp->attendance == false) // if absent student is found
			{
				found = true; // absent student found
				cout << "Student Name: " << temp->name << endl;
				cout << "Student Intial: " << temp->intials << endl;
				if (temp->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}

				if (temp->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}
				cout << "SeatNumber: " << temp->seatnumber << endl;
				//print out team 
				// if team is 0 student has no team
				if (temp->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << temp->team << endl;
				}

				cout << "Pair Number: " << temp->pair << endl;
				cout << "Major: " << temp->major << endl;
				cout << '\n';

			}
			temp = temp->next; // advances the list
		}
		if (found == false) // if there are no absent students
		{
			cout << "No Absent Students " << endl;
		}
	}

	// Display Present Students
	// Search list for present students then prints them
	void DisplayPresent()
	{
		temp = head; // start at head
		bool found = false;
		cout << "Present Students " << endl;
		while (temp != NULL)
		{
			if (temp->attendance == true) // if present student is found
			{
				found = true; // absent student found
				cout << "Student Name: " << temp->name << endl;
				cout << "Student Intial: " << temp->intials << endl;
				if (temp->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}

				if (temp->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}
				cout << "SeatNumber: " << temp->seatnumber << endl;
				//print out team 
				// if team is 0 student has no team
				if (temp->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << temp->team << endl;
				}

				cout << "Pair Number: " << temp->pair << endl;
				cout << "Major: " << temp->major << endl;
				cout << '\n';

			}
			temp = temp->next; // advances the list
		}
		if (found == false) // if there are no absent students
		{
			cout << "No Present Students " << endl;
		}
	}

	// Adds or Removes the first student
	// lets user choose to remove or add a student to the front of the list
	void AddRemoveFirst()
	{
		int choice; // user choice to add the student or remove the student from front
		bool valid = false; // if the response is valid
		student* delptr = NULL; // delete ptr to delete a student
		temp = head; // starts at the front of the list
		cout << "Student Name: " << temp->name << endl;
		cout << "Student Intial: " << temp->intials << endl;
		if (temp->attendance == true)
		{
			cout << "Student Attendance: Present" << endl;
		}
		else
		{
			cout << "Student Attendance: Absent" << endl;
		}

		if (temp->seat == true)
		{
			cout << "Student is in seat" << endl;
		}
		else
		{
			cout << "Student is not in seat" << endl;
		}
		cout << "SeatNumber: " << temp->seatnumber << endl;
		//print out team 
		// if team is 0 student has no team
		if (temp->team == 0)
		{
			cout << "Team Number: No Team " << endl;
		}
		else
		{
			cout << "Team Number: " << temp->team << endl;
		}

		cout << "Pair Number: " << temp->pair << endl;
		cout << "Major: " << temp->major << endl;
		cout << '\n';

		while (valid == false)
		{
			cout << "What Would you like to do?" << endl;
			cout << "1: Remove First Student " << endl;
			cout << "2: Add Student to Front of List" << endl;
			cin >> choice;
			// deleting the first student
			if (choice == 1)
			{
				delptr = temp; // delete old head
				head = temp->next; // make old head ->next new head
				head->prev = NULL; // new head prev is NULL
				valid = true;
				cout << "Student " << temp->name << " removed from list " << endl;
			}
			// Add Student to Front of the list
			else if (choice == 2)
			{
				valid = true;
				string name; // student name
				string intial; // student intial
				bool seat; // student seat
				int seatnumber; // student seat number
				bool inclass; // in class
				bool attendance; // attended class or not
				bool validseat = false; // check if user awnsers are valid
				bool validclass = false; // chekc if user awnser is valid
				string yesorno; // ask the user yes or no
				int team; // student team
				int pair; // Student pair
				string major; // student major

				// Enter Data for new student
				cout << "Student Name: " << endl; // ask for name
				cin.ignore();
				getline(cin, name);
				cout << "Student Intial: " << endl; // ask for intial
				cin >> intial;
				// ask for student seat number:
				cout << "What is the Student's seat number: " << endl;
				cin >> seatnumber;
				// ask if user is in class or not
				while (validclass == false) // checks if awnser is valid
				{
					cout << "Is the Student in class(yes/no)? " << endl;
					cin >> yesorno;

					if (yesorno == "yes")
					{
						validclass = true;
						inclass = true;

						// ask if student is in his seat or not( has to be in class to be in seat
						while (validseat == false)  // checks if awnser is valid
						{
							cout << "Is the Student in his/her seat(yes/no)? " << endl;
							cin >> yesorno;

							if (yesorno == "yes")
							{
								validseat = true;
								seat = true;
							}
							else if (yesorno == "no")
							{
								validseat = true;
								seat = false;
							}
							else
							{
								cout << "Not Valid Choice" << endl;
							}
						}
					}
					// student not in class also not in seat
					else if (yesorno == "no")
					{
						validclass = true;
						inclass = false;
						seat = false; // cant be in seat if not in class


					}
					else
					{
						cout << "Not Valid Choice" << endl;
					}

				}

				// Marks Student Attendance based on seat /
				if (inclass == true)
				{
					attendance = true; // student attended class
				}
				else
				{
					attendance = false; // student absent
				}

				cout << "Student Team(0-4): " << endl; // ask for team number
				cin >> team;
				cout << "Student Pair: " << endl; // ask for pair number
				cin >> pair;
				cout << "Studetn Major: " << endl; // ask for major
				cin.ignore();
				getline(cin, major);

				// use the addStudent function to add a student to the front of the list
				AddStudent(name, intial, inclass, seatnumber, seat, attendance, team, pair, major);

				// Display New Student
				cout << "Student Name: " << head->name << endl;
				cout << "Student Intial: " << head->intials << endl;

				if (head->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}

				if (head->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}
				cout << "SeatNumber: " << head->seatnumber << endl;
				//print out team 
				// if team is 0 student has no team
				if (head->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << head->team << endl;
				}

				cout << "Pair Number: " << head->pair << endl;
				cout << "Major: " << head->major << endl;
				cout << '\n';
			}
			// invalid choice
			else
			{
				cout << "Invalid Input Try Again " << endl;
			}

		}
		cout << '\n';
		delete delptr;
	}

	// Adds or Removes the Last Student
	// Gives the user a choice to add or remove last student
	// if add it adds brand new student 
	// if remove removes last student
	void AddRemoveLast()
	{
		int choice; // user choice to add the student or remove the student from front
		bool valid = false; // if the response is valid
		student* delptr = NULL; // delete ptr to delete a student
		temp = tail; // starts at the back of the list

		cout << "Student Name: " << temp->name << endl;
		cout << "Student Intial: " << temp->intials << endl;
		if (temp->attendance == true)
		{
			cout << "Student Attendance: Present" << endl;
		}
		else
		{
			cout << "Student Attendance: Absent" << endl;
		}

		if (temp->seat == true)
		{
			cout << "Student is in seat" << endl;
		}
		else
		{
			cout << "Student is not in seat" << endl;
		}
		cout << "SeatNumber: " << temp->seatnumber << endl;
		//print out team 
		// if team is 0 student has no team
		if (temp->team == 0)
		{
			cout << "Team Number: No Team " << endl;
		}
		else
		{
			cout << "Team Number: " << temp->team << endl;
		}

		cout << "Pair Number: " << temp->pair << endl;
		cout << "Major: " << temp->major << endl;
		cout << '\n';

		while (valid == false)
		{
			cout << "What Would you like to do?" << endl;
			cout << "1: Remove Last Student " << endl;
			cout << "2: Add Student to the back of List" << endl;
			cin >> choice;
			// deleting the last student
			if (choice == 1)
			{
				delptr = temp; // delete old tail
				tail = temp->prev; // make old tail-> prev the new tail
				tail->next = NULL; // new tail next -> NULL
				valid = true;
				cout << "Student " << temp->name << " removed from list " << endl;
				cout << '\n';
			}
			// Add Student to the Back of the List
			else if (choice == 2)
			{
				valid = true;
				string name; // student name
				string intial; // student intial
				bool seat; // student seat
				int seatnumber; // student seat number
				bool inclass; // in class
				bool attendance; // attended class or not
				bool validseat = false; // check if user awnsers are valid
				bool validclass = false; // chekc if user awnser is valid
				string yesorno; // ask the user yes or no
				int team; // student team
				int pair; // Student pair
				string major; // student major

				// Enter Data for new student
				cout << "Student Name: " << endl; // ask for name
				cin.ignore();
				getline(cin, name);
				cout << "Student Intial: " << endl; // ask for intial
				cin >> intial;
				// ask for student seat number:
				cout << "What is the Student's seat number: " << endl;
				cin >> seatnumber;
				// ask if user is in class or not
				while (validclass == false) // checks if awnser is valid
				{
					cout << "Is the Student in class(yes/no)? " << endl;
					cin >> yesorno;

					if (yesorno == "yes")
					{
						validclass = true;
						inclass = true;

						// ask if student is in his seat or not( has to be in class to be in seat
						while (validseat == false)  // checks if awnser is valid
						{
							cout << "Is the Student in his/her seat(yes/no)? " << endl;
							cin >> yesorno;

							if (yesorno == "yes")
							{
								validseat = true;
								seat = true;
							}
							else if (yesorno == "no")
							{
								validseat = true;
								seat = false;
							}
							else
							{
								cout << "Not Valid Choice" << endl;
							}
						}
					}
					// student not in class also not in seat
					else if (yesorno == "no")
					{
						validclass = true;
						inclass = false;
						seat = false; // cant be in seat if not in class


					}
					else
					{
						cout << "Not Valid Choice" << endl;
					}

				}

				// Marks Student Attendance based on seat /
				if (inclass == true)
				{
					attendance = true; // student attended class
				}
				else
				{
					attendance = false; // student absent
				}

				cout << "Student Team(0-4): " << endl; // ask for team number
				cin >> team;
				cout << "Student Pair: " << endl; // ask for pair number
				cin >> pair;
				cout << "Studetn Major: " << endl; // ask for major
				cin.ignore();
				getline(cin, major);

				// Put New Student at the back of the list making it the new tail by using fillclassroom function
				FillStudentClassroom(name, intial, inclass, seat, seatnumber, attendance, team, pair, major);

				// Display New Student
				cout << "Student Name: " << tail->name << endl;
				cout << "Student Intial: " << tail->intials << endl;

				if (tail->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}

				if (tail->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}
				cout << "SeatNumber: " << tail->seatnumber << endl;
				//print out team 
				// if team is 0 student has no team
				if (tail->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << tail->team << endl;
				}

				cout << "Pair Number: " << tail->pair << endl;
				cout << "Major: " << tail->major << endl;
				cout << '\n';
			}
			else
			{
				cout << "Invalid Choice Try Again " << endl;
			}

		}
	}

	// Disply Students In Class Physically
	// Searches list for Students in class = true then prints accordingly
	void DisplayInClass()
	{
		bool found = false; // if Students are found or not
		temp = head; // start at the head of the list
		cout << "Students Physically In Class " << endl;
		cout << '\n';
		while (temp != NULL) // go thru list till last node
		{
			if (temp->inclass == true) // if inclass physically is found print student
			{
				found = true; // found = true
				cout << "Student Name: " << temp->name << endl;
				cout << "Student Intial: " << temp->intials << endl;
				// print out attendance
				if (temp->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}
				// print out if he/she is physically in class
				if (temp->inclass == true)
				{
					cout << "Student is in class" << endl;
				}
				else
				{
					cout << "Student is not in class" << endl;
				}

				// print out if he/she is in their seat
				if (temp->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}
				cout << "SeatNumber: " << temp->seatnumber << endl;
				//print out team 
				// if team is 0 student has no team
				if (temp->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << temp->team << endl;
				}

				cout << "Pair Number: " << temp->pair << endl;
				cout << "Major: " << temp->major << endl;
				cout << '\n';
			}
			temp = temp->next; // traverse list
		}
		if (found == false) // no students physically in class foun
		{
			cout << "No Students Physically In Class " << endl;
		}
	}
	
	// Change Data on Student
	// Search list for name then display student then ask user what he wants to change  then change it and display
	// parameter list: student name
	void ChangeData(string name)
	{
		temp = head;// start at the head of list
		string newname; // if user wants to enter new name
		string newintials; // if user wants to enter new intials
		int seatnumber; // if user wants to change student seat number
		int newpair; // if user wants to change pair number
		int newteam; // if the user wants to change team
		string newmajor; // if user wants to change new major
		bool found = false; // if student is found or not
		bool valid = false; // check the users choice if valid or not
		int choice; // choice the user makes

		while (temp != NULL) // go to the end of the list
		{
			if (temp->name == name) //if student is found in list
			{
				found = true; // found will be true
				// Print student
				cout << "Student Name: " << temp->name << endl;
				cout << "Student Intial: " << temp->intials << endl;
				// print out attendance
				if (temp->attendance == true)
				{
					cout << "Student Attendance: Present" << endl;
				}
				else
				{
					cout << "Student Attendance: Absent" << endl;
				}
				// print out if he/she is physically in class
				if (temp->inclass == true)
				{
					cout << "Student is in class" << endl;
				}
				else
				{
					cout << "Student is not in class" << endl;
				}

				// print out if he/she is in their seat
				if (temp->seat == true)
				{
					cout << "Student is in seat" << endl;
				}
				else
				{
					cout << "Student is not in seat" << endl;
				}
				cout << "SeatNumber: " << temp->seatnumber << endl;
				//print out team 
				// if team is 0 student has no team
				if (temp->team == 0)
				{
					cout << "Team Number: No Team " << endl;
				}
				else
				{
					cout << "Team Number: " << temp->team << endl;
				}

				cout << "Pair Number: " << temp->pair << endl;
				cout << "Major: " << temp->major << endl;
				cout << '\n';

				while (valid == false) // check user input
				{
					cout << "What Data would you like to change(1-6)" << endl;
					cout << "1: Student Name " << endl;
					cout << "2: Student Intials " << endl;
					cout << "3: Student Seat Number " << endl;
					cout << "4: Student Pair Number " << endl;
					cout << "5: Student's Team " << endl;
					cout << "6: Student's Major " << endl;
					cin >> choice; 
					cout << '\n';
					if (choice == 1) // Change Student nmame
					{
						cout << "What is the Student's New Name?: " << endl;
						cin.ignore();
						getline(cin, newname);
						temp->name = newname;
						valid = true;
					}
					else if (choice == 2) // Change Student Intials
					{
						cout << "What is the Student's New Intials" << endl;
						cin.ignore();
						getline(cin, newintials);
						temp->intials = newintials;
						valid = true;
					}
					else if (choice == 3) // change Student Seat number
					{
						cout << "What is the Student's New Seat Number " << endl;
						cin >> seatnumber;
						temp->seatnumber = seatnumber;
						valid = true;
					}
					else if (choice == 4) // Change Student pair number
					{
						cout << "What is the Student's New Pair Number" << endl;
						cin >> newpair;
						temp->pair = newpair;
						valid = true;
					}
					else if (choice == 5) // Change Student Team
					{
						cout << "What is the Student's New Team(0-4) " << endl;
						cin >> newteam;
						temp->team = newteam;
						valid = true;
					}
					else if (choice == 6) // Change Students Major
					{
						cout << "What is the Student's New Major " << endl;
						cin.ignore();
						getline(cin, newmajor);
						temp->major = newmajor;
						valid = true;
					}
					else
					{
						cout << "Invaild Input Try Again" << endl;
					}

					// Print Changed Student
					cout << "Student Name: " << temp->name << endl;
					cout << "Student Intial: " << temp->intials << endl;
					// print out attendance
					if (temp->attendance == true)
					{
						cout << "Student Attendance: Present" << endl;
					}
					else
					{
						cout << "Student Attendance: Absent" << endl;
					}
					// print out if he/she is physically in class
					if (temp->inclass == true)
					{
						cout << "Student is in class" << endl;
					}
					else
					{
						cout << "Student is not in class" << endl;
					}

					// print out if he/she is in their seat
					if (temp->seat == true)
					{
						cout << "Student is in seat" << endl;
					}
					else
					{
						cout << "Student is not in seat" << endl;
					}
					cout << "SeatNumber: " << temp->seatnumber << endl;
					//print out team 
					// if team is 0 student has no team
					if (temp->team == 0)
					{
						cout << "Team Number: No Team " << endl;
					}
					else
					{
						cout << "Team Number: " << temp->team << endl;
					}

					cout << "Pair Number: " << temp->pair << endl;
					cout << "Major: " << temp->major << endl;
					cout << '\n';
				}

			}
			temp = temp->next; // traverse the list
		}
		// if Student is Not Found
		if (found == false)
		{
			cout << "Student " << name << " was not Found" << endl;
			cout << '\n';
		}
		
	}

	// Size of Student List
	// Traverse the list have a counter count up all the students within list till it hits the end
	// return the amount of students in List

	void SizeList()
	{
		temp = head; // start at the head of the list
		int counter = 0; // counter for students
		cout << '\n';
		while (temp != NULL)
		{
			counter++; // increment counter for every node
			temp = temp->next; // traverse and advance the list
		}
		cout << "Students in List: " << counter << endl;
		cout << '\n';
	}

	// Reverse the List
	// Set the tail to the head set the head to the tail; then go accordingly with next
	void ReverseList()
	{
		student* temp2 = new student; // creat new temp to point to the tail
		temp = head; // temp pointer saves the old head
		temp2 = tail; // temp 2 points to the old tail
		head = tail; // tail becomes head

		while (temp2 != NULL) // until temp2 is done traversing list
		{
			temp2->next = temp2->prev; // make the old tail(head)->next the old(tail) prev
			temp2->prev = temp2->next; //make the old tail(head)->prev the old tail next
			temp2 = temp2->next; // traverse the list
		}
		tail = temp; //  tail will equal the old head
		PrintForward();
		delete temp2; // delete the temp 2
	}
	
	// Sort List
	// Sort list aplahbetically by user choice of name,intials,major by using an array them sorting it then searching list for array in order than print
	// can only handle 1000 students
	void SortList()
	{
		int choice; // let user choose what to sort by
		string alphasort[1000]; // array to put in students name
		int counter = 0; // count the number of elements
		temp = head; // start at the head
		bool valid = false; // check user awnser if valid

		cout << "Sort Alphabetically by " << endl;
		cout << "1: Name" << endl;
		cout << "2: Intials" << endl;
		cout << "3: Major " << endl;
		cout << "Enter Options(1-3): " << endl;
		cin >> choice;
		while (valid == false)
		{
			if (choice == 1)
			{
				valid = true;
				// puting list names into arrary
				while (temp != NULL) // when its at the end of list
				{
					alphasort[counter] = temp->name; // put names into arary
					counter++; // add to counter
					temp = temp->next; // traverse list
				}
				
				sort(alphasort, alphasort + counter); // sorting the arrary alphabetically

				int i = 0; // while loop incrementer
				temp = head; // point to the head
				while (i < counter) // while not all emlements are searched
				{
					while (temp != NULL) // until we reach end of list
					{
						if (temp->name == alphasort[i])
						{
							// Display list as we sort
							cout << "Student Name: " << temp->name << endl;
							cout << "Student Intial: " << temp->intials << endl;
							// print out attendance
							if (temp->attendance == true)
							{
								cout << "Student Attendance: Present" << endl;
							}
							else
							{
								cout << "Student Attendance: Absent" << endl;
							}
							// print out if he/she is physically in class
							if (temp->inclass == true)
							{
								cout << "Student is in class" << endl;
							}
							else
							{
								cout << "Student is not in class" << endl;
							}

							// print out if he/she is in their seat
							if (temp->seat == true)
							{
								cout << "Student is in seat" << endl;
							}
							else
							{
								cout << "Student is not in seat" << endl;
							}
							cout << "SeatNumber: " << temp->seatnumber << endl;
							//print out team 
							// if team is 0 student has no team
							if (temp->team == 0)
							{
								cout << "Team Number: No Team " << endl;
							}
							else
							{
								cout << "Team Number: " << temp->team << endl;
							}

							cout << "Pair Number: " << temp->pair << endl;
							cout << "Major: " << temp->major << endl;
							cout << '\n';
							i++; // increment main loop
							temp = head; // start over if u find
						}
						else
						{
							temp = temp->next; // traverse the list
						}
					}
				}
			}
			
			else if (choice == 2) // sort by intials
			{
				valid = true;
				// puting list intials into arrary
				while (temp != NULL) // when its at the end of list
				{
					alphasort[counter] = temp->intials; // put intials into arary
					counter++; // add to counter
					temp = temp->next; // traverse list
				}
				sort(alphasort, alphasort + counter); // sorting the arrary alphabetically

				int i = 0; // while loop incrementer
				temp = head; // point to the head
				while (i < counter) // while not all emlements are searched
				{
					while (temp != NULL) // until we reach end of list
					{
						if (temp->intials == alphasort[i]) // of intials are found
						{
							// Display list as we sort
							cout << "Student Name: " << temp->name << endl;
							cout << "Student Intial: " << temp->intials << endl;
							// print out attendance
							if (temp->attendance == true)
							{
								cout << "Student Attendance: Present" << endl;
							}
							else
							{
								cout << "Student Attendance: Absent" << endl;
							}
							// print out if he/she is physically in class
							if (temp->inclass == true)
							{
								cout << "Student is in class" << endl;
							}
							else
							{
								cout << "Student is not in class" << endl;
							}

							// print out if he/she is in their seat
							if (temp->seat == true)
							{
								cout << "Student is in seat" << endl;
							}
							else
							{
								cout << "Student is not in seat" << endl;
							}
							cout << "SeatNumber: " << temp->seatnumber << endl;
							//print out team 
							// if team is 0 student has no team
							if (temp->team == 0)
							{
								cout << "Team Number: No Team " << endl;
							}
							else
							{
								cout << "Team Number: " << temp->team << endl;
							}

							cout << "Pair Number: " << temp->pair << endl;
							cout << "Major: " << temp->major << endl;
							cout << '\n';
							i++; // increment main loop
							temp = head; // start over when one element is found
						}
						else
						{
							temp = temp->next; // traverse the list
						}
					}
				}
			}
			else if (choice == 3) // sort by major // discrepency will print twice or more for people with the same Major
			{
				valid = true;
				// puting list major into arrary
				while (temp != NULL) // when its at the end of list
				{
					alphasort[counter] = temp->major; // put major into arary
					counter++; // add to counter
					temp = temp->next; // traverse list
				}
				sort(alphasort, alphasort + counter); // sorting the arrary alphabetically

				int i = 0; // while loop incrementer
				temp = head; // point to the head
				while (i < counter) // until we print out all elements in list
				{
					if (temp->major == alphasort[i]) // if major is found print out
					{
						// Display list as we sort
						cout << "Student Name: " << temp->name << endl;
						cout << "Student Intial: " << temp->intials << endl;
						// print out attendance
						if (temp->attendance == true)
						{
							cout << "Student Attendance: Present" << endl;
						}
						else
						{
							cout << "Student Attendance: Absent" << endl;
						}
						// print out if he/she is physically in class
						if (temp->inclass == true)
						{
							cout << "Student is in class" << endl;
						}
						else
						{
							cout << "Student is not in class" << endl;
						}

						// print out if he/she is in their seat
						if (temp->seat == true)
						{
							cout << "Student is in seat" << endl;
						}
						else
						{
							cout << "Student is not in seat" << endl;
						}
						cout << "SeatNumber: " << temp->seatnumber << endl;
						//print out team 
						// if team is 0 student has no team
						if (temp->team == 0)
						{
							cout << "Team Number: No Team " << endl;
						}
						else
						{
							cout << "Team Number: " << temp->team << endl;
						}

						cout << "Pair Number: " << temp->pair << endl;
						cout << "Major: " << temp->major << endl;
						cout << '\n';

					}
						if (temp->next == NULL) // increments when list reaches end then resets the list
						{
							temp = head; // goes back to the front
							i++;

						}

					temp = temp->next; // traverse list
				}

			}
			else
			{
				cout << "Invalid Choice Try Again" << endl;
			}
		}
	}

};

int main()
{
	List Classroom; // doubly linked list

	bool quit = false; // Menu loop till user wants to exit
	int choice; // function choice user wants to make
	while (quit == false)
	{
		cout << "Classroom List " << endl;
		cout << "0: Exit" << endl;
		cout << "1: Fill Student Classroom List" << endl;
		cout << "2: Insert Student into the List " << endl;
		cout << "3: Display List Forward " << endl;
		cout << "4: Display List Backward " << endl;
		cout << "5: Find Student" << endl;
		cout << "6: Remove Student" << endl;
		cout << "7: Assign Student to Team" << endl;
		cout << "8: Replace Student " << endl;
		cout << "9: Find Students by a Given Team " << endl;
		cout << "10: Order Students by Team then Display" << endl;
		cout << "11: Mark Student Absent or Not/Mark Student in Class or Not" << endl;
		cout << "12: Display Absent Students " << endl;
		cout << "13: Display Present Students " << endl;
		cout << "14: Display Students Physically Present " << endl;
		cout << "15: Add or Remove First Student " << endl;
		cout << "16: Add or Remove Last Student " << endl;
		cout << "17: Change Data of Student " << endl;
		cout << "18: Reverse the List " << endl;
		cout << "19: Display Size of List " << endl;
		cout << "20: Sort Alphabetically" << endl;
		cout << "21: Dummy Data" << endl;
		cout << "22: Test Script" << endl;
		cout << "Enter your choice(0-22): " << endl;
		cin >> choice;

		// Exit Program
		if (choice == 0)
		{
			quit = true;
			cout << "Exiting Program" << endl;
		}

		// Fill the Classroom with students
		if (choice == 1)
		{


			string userchoice; // choice to repeat
			bool repeat = false; // will not repeat unless user says to
			do
			{
				string name; // student name
				string intial; // student intial
				bool seat; // student seat
				int seatnumber; // student seat number
				bool inclass; // in class
				bool attendance; // attended class or not
				bool validseat = false; // check if user awnsers are valid
				bool validclass = false; // chekc if user awnser is valid
				string yesorno; // ask the user yes or no
				int team; // student team
				int pair; // Student pair
				string major; // student major

				cout << "Student Name: " << endl; // ask for name
				cin.ignore();
				getline(cin, name);
				cout << "Student Intial: " << endl; // ask for intial
				cin >> intial;
				// ask for student seat number:
				cout << "What is the Student's seat number: " << endl;
				cin >> seatnumber;
				// ask if user is in class or not
				while (validclass == false) // checks if awnser is valid
				{
					cout << "Is the Student in class(yes/no)? " << endl;
					cin >> yesorno;

					if (yesorno == "yes")
					{
						validclass = true;
						inclass = true;

						// ask if student is in his seat or not( has to be in class to be in seat
						while (validseat == false)  // checks if awnser is valid
						{
							cout << "Is the Student in his/her seat(yes/no)? " << endl;
							cin >> yesorno;

							if (yesorno == "yes")
							{
								validseat = true;
								seat = true;
							}
							else if (yesorno == "no")
							{
								validseat = true;
								seat = false;
							}
							else
							{
								cout << "Not Valid Choice" << endl;
							}
						}
					}
					// student not in class also not in seat
					else if (yesorno == "no")
					{
						validclass = true;
						inclass = false;
						seat = false; // cant be in seat if not in class


					}
					else
					{
						cout << "Not Valid Choice" << endl;
					}
				}

				// Marks Student Attendance based on seat /
				if (inclass == true)
				{
					attendance = true; // student attended class
				}
				else
				{
					attendance = false; // student absent
				}

				cout << "Student Team(0-4): " << endl; // ask for team number
				cin >> team;
				cout << "Student Pair: " << endl; // ask for pair number
				cin >> pair;
				cout << "Studetn Major: " << endl; // ask for major
				cin.ignore();
				getline(cin, major);

				// Makes a student object or node inside the classroom
				Classroom.FillStudentClassroom(name, intial, inclass, seat, seatnumber, attendance, team, pair, major);

				bool valid = false; // verify if choice is valid
				while (valid == false)
				{
					cout << "Would You Like to Add Another Student(yes/no)" << endl;
					cin >> userchoice;

					if (userchoice == "yes")
					{
						valid = true;
						repeat = true;
					}
					else if (userchoice == "no")
					{
						valid = true;
						repeat = false;
					}
					else
					{
						cout << "Not Valid Choice " << endl;
					}
				}
			} while (repeat == true);
		}

		// Add a Student to front of list
		if (choice == 2)
		{
			string userchoice; // choice to repeat
			bool repeat = false; // will not repeat unless user says to
			do
			{
				string name; // student name
				string intial; // student intial
				bool seat; // student seat
				int seatnumber; // student seat number
				bool inclass; // in class
				bool attendance; // attended class or not
				bool validseat = false; // check if user awnsers are valid
				bool validclass = false; // chekc if user awnser is valid
				string yesorno; // ask the user yes or no
				int team; // student team
				int pair; // Student pair
				string major; // student major

				cout << "Student Name: " << endl; // ask for name
				cin.ignore();
				getline(cin, name);
				cout << "Student Intial: " << endl; // ask for intial
				cin >> intial;
				// ask for student seat number:
				cout << "What is the Student's seat number: " << endl;
				cin >> seatnumber;

				// ask if user is in class or not
				while (validclass == false) // checks if awnser is valid
				{
					cout << "Is the Student in class(yes/no)? " << endl;
					cin >> yesorno;

					if (yesorno == "yes")
					{
						validclass = true;
						inclass = true;

						// ask if student is in his seat or not( has to be in class to be in seat
						while (validseat == false)  // checks if awnser is valid
						{
							cout << "Is the Student in his/her seat(yes/no)? " << endl;
							cin >> yesorno;

							if (yesorno == "yes")
							{
								validseat = true;
								seat = true;
							}
							else if (yesorno == "no")
							{
								validseat = true;
								seat = false;
							}
							else
							{
								cout << "Not Valid Choice" << endl;
							}
						}
					}
					// student not in class also not in seat
					else if (yesorno == "no")
					{
						validclass = true;
						inclass = false;
						seat = false; // cant be in seat if not in class


					}
					else
					{
						cout << "Not Valid Choice" << endl;
					}
				}

				// Marks Student Attendance based on seat / class
				if (inclass == true)
				{
					attendance = true;
				}
				else
				{
					attendance = false;
				}

				cout << "Student Team(0-4): " << endl; // ask for team number
				cin >> team;
				cout << "Student Pair: " << endl; // ask for pair number
				cin >> pair;
				cout << "Studetn Major: " << endl; // ask for major
				cin.ignore();
				getline(cin, major);

				// Makes a student object or node inside the classroom
				Classroom.AddStudent(name, intial, inclass, seatnumber, seat, attendance, team, pair, major);

				bool valid = false; // verify if choice is valid
				while (valid == false)
				{
					cout << "Would You Like to Add Another Student(yes/no)" << endl;
					cin >> userchoice;

					if (userchoice == "yes")
					{
						valid = true;
						repeat = true;
					}
					else if (userchoice == "no")
					{
						valid = true;
						repeat = false;
					}
					else
					{
						cout << "Not Valid Choice " << endl;
					}
				}
			} while (repeat == true);
		}

		// Display list foward
		if (choice == 3)
		{
			Classroom.PrintForward();
		}

		// Display list Backward
		if (choice == 4)
		{
			Classroom.PrintBack();
		}

		// find student by name
		if (choice == 5)
		{
		

			Classroom.FindStudent();
		}

		// Remove Student
		if (choice == 6)
		{
			string name; // student name 
			cout << "What is the Student's Name? " << endl;
			cin.ignore();
			getline(cin, name);

			Classroom.RemoveStudent(name);
		}

		// Assign Student to team
		if (choice == 7)
		{
			string name; // student name 
			cout << "What is the Student's Name? " << endl;
			cin.ignore();
			getline(cin, name);

			Classroom.AssignTeam(name);
		}

		// Replace student
		if (choice == 8)
		{
			string intials; // student intials
			cout << "What is the Student's Intials? " << endl;
			cin >> intials;

			Classroom.ReplaceStudent(intials);
		}

		// Find Students by given team
		if (choice == 9)
		{
			int team; // int team
			cout << "Enter Team Number(0-4): " << endl;
			cin >> team;

			Classroom.DisplayStudentTeam(team);

		}

		// Order Students by Team then Display
		if (choice == 10)
		{
			Classroom.OrderTeam();
		}

		// Mark Student Absent or not
		if (choice == 11)
		{
			string name;// student name to search
			cout << "What is the Student's name? " << endl;
			cin >> name;

			Classroom.MarkAbsent(name);
		}

		// Display all absent Students
		if (choice == 12)
		{
			Classroom.DisplayAbsent();
		}

		// Display all Present Students
		if (choice == 13)
		{
			Classroom.DisplayPresent();
		}

		// Display All Physically in Class Students
		if (choice == 14)
		{
			Classroom.DisplayInClass();
		}

		// Add or Remove the first story
		if (choice == 15)
		{
			Classroom.AddRemoveFirst();
		}

		// Add or Remove the Last Story
		if (choice == 16)
		{
			Classroom.AddRemoveLast();
		}

		// Change Student Data 
		if (choice == 17)
		{
			string name;// student name to search
			cout << "What is the Student's name? " << endl;
			cin >> name;

			Classroom.ChangeData(name);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
		}

		// Reverse the list
		if (choice == 18)
		{
			Classroom.ReverseList();
		}

		// Display Size of List
		if (choice == 19)
		{
			Classroom.SizeList();
		}

		// Sort List Alphabetically
		if (choice == 20)
		{
			Classroom.SortList();
		}
		// Dummy Data
		if (choice == 21)
		{
			Classroom.FillStudentClassroom("Bob", "BRB", true, true, 2, true, 2, 22, "DANCE");
			Classroom.FillStudentClassroom("Andrew", "ADL", true, true, 1, true, 1, 1, "CS");
			Classroom.FillStudentClassroom("Lauren", "LYT", false, false, 3, false, 1, 3, "PSYCH");
			Classroom.FillStudentClassroom("Rivada", "ARL", true, false, 7, true, 2, 2, "CS");
			Classroom.FillStudentClassroom("Chris", "CWP", false, false, 39, false, 0, 0, "BIOLOGY");
			Classroom.FillStudentClassroom("Lee", "LPP", false, false, 10, true, 3, 10, "ANTHRO");
			Classroom.FillStudentClassroom("Kousei", "KNA", false, false, 34, false, 4, 20, "MUSIC");
			cout << "Dummy Data Loaded" << endl;
			cout << '\n';
		}

		// TestScript
		if (choice == 22)
		{
			Classroom.FillStudentClassroom("Bob", "BRB", true, true, 2, true, 2, 22, "DANCE");
			Classroom.FillStudentClassroom("Andrew", "ADL", true, true, 1, true, 1, 1, "CS");
			Classroom.FillStudentClassroom("Lauren", "LYT", false, false, 3, false, 1, 3, "PSYCH");
			Classroom.FillStudentClassroom("Rivada", "ARL", true, false, 7, true, 2, 2, "CS");
			Classroom.FillStudentClassroom("Chris", "CWP", false, false, 39, false, 0, 0, "BIOLOGY");
			Classroom.FillStudentClassroom("Lee", "LPP", false, false, 10, true, 3, 10, "ANTHRO");
			Classroom.FillStudentClassroom("Kousei", "KNA", false, false, 34, false, 4, 20, "MUSIC");
			cout << "Dummy Data Loaded" << endl;
			cout << "Show Print Forward Function" << endl;
			Classroom.PrintForward();
			
			cout << "Fill Student Classroom List Function" << endl;
			Classroom.FillStudentClassroom("Kent", "KPP", true, true, 0, true, 0, 0, "DATASTUCTURES");
			Classroom.PrintForward();

			cout << "Insert Student Function" << endl;
			Classroom.AddStudent("NewStudent", "NSS", true, false, 11, true, 3, 11, "NONE");
			Classroom.PrintForward();

			cout << "Print List Backwards Function" << endl;
			Classroom.PrintBack();

			cout << "Find Student Function" << endl;
			Classroom.FindStudent();

			cout << "Remove Student Function" << endl;
			Classroom.RemoveStudent("NewStudent");
			Classroom.PrintForward();

			cout << "Assign Team Function(EX: Assign team to kent)" << endl;
			Classroom.AssignTeam("Kent");

			cout << "Replace Student Function(EX: replace studend Lee)" << endl; 
			Classroom.ReplaceStudent("LPP");

			cout << "Find Student By Given Team Function(EX: Show Team 2 Students)" << endl;
			Classroom.DisplayStudentTeam(2);

			cout << "Order Students by Team Function" << endl;
			Classroom.OrderTeam();

			cout << "Mark Student Absent or Not" << endl;
			cout << "Mark Student in Class or Not Function(EX: Mark Lauren Absent of Not)" << endl;
			Classroom.MarkAbsent("Lauren");

			cout << "Display Absent Students Function" << endl;
			Classroom.DisplayAbsent();

			cout << "Display Present Students Function" << endl;
			Classroom.DisplayPresent();

			cout << "Display Student Physically Present Function" << endl;
			Classroom.DisplayPresent();

			cout << "Add or Remove First Student Function" << endl;
			Classroom.AddRemoveFirst();

			cout << "Add or Remove Last Student Function" << endl;
			Classroom.AddRemoveLast();

			cout << "Change Data of Student Function(Ex: Change Andrew data)" << endl;
			Classroom.ChangeData("Andrew");

			cout << "Reverse List Function " << endl;
			Classroom.ReverseList();
			Classroom.PrintForward();

			cout << "Display Size of List Function" << endl;
			Classroom.SizeList();

			cout << "Sort Alphabetically Function " << endl;
			Classroom.SortList();
		}

	}
	system("pause");
	return 0;
}