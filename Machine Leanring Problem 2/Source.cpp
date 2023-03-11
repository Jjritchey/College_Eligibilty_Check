//Justin Ritchey completing Machine leanring 2 for Intro to C++ Started on 5/24/2020 
//Attempting to create a program that reads a data file and delcares if a person is eligable to be accepted in two seperate colleges

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


int main() {

	ifstream file("mp3accept.txt");                                                                  //Opening file with student applications
	int i = 1;                                                                                       //Storing number of applicants (+1 for correct count) (-1 at the end for correct count)
	int musicAccepted = 0;                                                                           //To hold how many Music students have been accepted
	int libAccepted = 0;                                                                             //To hold how many Liberal Art students have been accepted

	file.clear();
	file.seekg(0, ios::beg);

	cout << "Acceptance to College by Justin Ritchey\n\n";

	if(file.is_open());
	{
		string school;                                                                                //Storing school
		float gpa;                                                                                    //Storing Gpa
		int sat1;                                                                                     //Storing first SAT score
		int sat2;                                                                                     //Storing second SAT score
		string alum;                                                                                  //Storing either "Y" or "N" if parents were alumni
		
		cout << fixed;
		cout << setprecision(1);                                                                      //Setting decimal spot to 1 place for the GPA


		while(file >> school >> gpa >> sat1 >> sat2 >> alum)                                          //Assinging data values to use in the loop
		{

			if(school == "L")                                                                          //Starting if/else statement to move into Liberal Arts school
			{
				if((alum == "Y")&&(gpa >= 3.0)&&(sat1 + sat2 >= 1000)&&(libAccepted < 5))              //Checking if Liberal Arts applicant has a alumni Parent, combined SAT is above 1000 and GPA is above 3.0 and only 5 people are accepted (will be accepted)
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Accepted to Liberal Arts!\n";
					cout << "****************************************\n\n";

					libAccepted++;
				}
				else if((alum == "N")&&(gpa >= 3.5)&&(sat1 + sat2 >= 1200)&&(libAccepted < 5))         //Liberal Arts applicant without alumni parent and 3.5 gpa plus 1200 combined SAT and only 5 people have been accepted (will be accepted)
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Accepted to Liberal Arts!\n";
					cout << "****************************************\n\n";

					libAccepted++;
				}
				else if((alum == "Y")&&(gpa < 3.0)&&(sat1 + sat2 < 1000))                              //Liberal Arts applicant with alumni status and gpa and sat less than needed
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Rejected - Both GPA and SAT scores are to low\n";
					cout << "****************************************\n\n";
				}
				else if((alum == "Y")&&(gpa < 3.0)&&(sat1 + sat2 >= 1000))                             //Liberal Arts applicant with alumni status and gpa less than needed
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Rejected - GPA score is to low\n";
					cout << "****************************************\n\n";
				}
				else if((alum == "Y")&&(gpa >= 3.0)&&(sat1 + sat2 < 1000))                            //Liberal Arts applicant with Alumni status and SAT scores less than needed
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Rejected - SAT scores are to low\n";
					cout << "****************************************\n\n";
				}
				else if((alum == "N")&&(gpa < 3.5)&&(sat1 + sat2 < 1200))                            //Liberal Arts applicant without Alumni status and both GPA and SAT are less than needed
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Rejected - Both GPA and SAT scores are to low\n";
					cout << "****************************************\n\n";
				}
				else if((alum == "N")&&(gpa < 3.5)&&(sat1 + sat2 >= 1200))                          //Liberal Arts applicant without ALumni status and GPA is less than needed
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Rejected - GPA score is to low\n";
					cout << "****************************************\n\n";
				}
				else if((alum == "N")&&(gpa >= 3.5)&&(sat1 + sat2 < 1200))                          //Liberal Arts applicant without Alumni status and SAT scores are less than needed
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Rejected - SAT scores are to low\n";
					cout << "****************************************\n\n";
				}
				else                                                                                //Liberal Arts applicant rejection when they meet requirements but 5 people have already been accepted
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Liberal Arts\n";
					cout << "Rejected - Applicant selection period is over\n";
					cout << "****************************************\n\n";
				}
				
			}
			else                                                                                      //Start of the If/Else statment for Music
			{
				if((sat1 >= 500)&&(sat2 >= 500)&&(musicAccepted < 3))                                 //Music applicant with both SAT scores greater than 500 and there has not already been 3 people accepted (will be accepted)
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Music\n";
					cout << "Accepted to Music!\n";
					cout << "****************************************\n\n";

					musicAccepted++;
				}
				else if((sat1 < 500) || (sat2 < 500))                                                 //Music applicant with either SAT score less than 500
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Music\n";
					cout << "Rejected - An SAT score is to low\n";
					cout << "****************************************\n\n";

				} 
				else                                                                                  //Music applicant rejection when they meet requirements but 3 people have already been accepted
				{
					cout << "Applicant #: " << i << '\n' << "School = " << school << " GPA = " << gpa << " Math = " << sat1 << " Verbal = " << sat2 << " Alumni = " << alum << '\n';
					cout << "Applying to Music\n";
					cout << "Rejected - Applicant selection period is over\n";
					cout << "****************************************\n\n";
				}
			}
			
			i++;                                                                                      //Counting total Applicants (starting with +1, will subtract one once loop has ended)
		}


		file.close();
	}
	cout << "\n";
	cout << "There were " << i - 1 << " applicants in the file\n";                                    //Printing out total applicants (-1 to make up for +1 when variable was made
	cout << "There were " << libAccepted << " acceptances to the Liberal Arts School\n";              //Printing out total applicants accepted to the School of Liberal Arts
	cout << "There were " << musicAccepted << " acceptances to the Music School\n";                   //Printing out total applicants accepted to the School of Music
	

	return 0;
}
