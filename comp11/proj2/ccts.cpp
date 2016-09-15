//                        Classy Concert Ticket Server
//
// The purpose of this program is to read in requests from potential customers
// for concert tickets and to sell them seats at a venue with 14 rows (A-N)
// and 20 seats (1-20) per row. There are higher priced seats ($200) in rows
// A-H seats 5-16. The rest of the seats are cheaper ($150). There is a discount
// of 10% if the buyer's party is split up. The program also prints out a map
// of the venue on request. The maximum number of tickets that can be requested
// is 12. The customer can request seats of price type hi, lo, or any. The
// program is designed to maximize profit. It also takes in a day of the week
// for which the customer can make these requests.
//
// James McCants
// 11/12/13
//

#include <iostream>
using namespace std;

#include "hall.h"
#include "string2int.h"

// Utilities
void command_loop(Hall event[]);
void do_rq(Hall event[]);
void do_pr(Hall event[]);
void do_ca(Hall event[]);

// main
//	purpose: declare the array of Halls and calls the command loop
//	argumnets: array of Halls, number of events
//	returns: 0
//	effects: sets up the array
//	notes: calls the array using a global constant

int main()
{
        Hall event[EVENTS];
        command_loop(event);

        return 0;
}

// command_loop
//	purpose: read in a command from the user and call the correct function  //               and loop until the user quits
//	arguments: array of Halls
//	returns: void
//	effects: does not modify the array
//	notes: input must be a valid command (RQ, PR, CA, QU). Runs until user
//             quits with 'QU'

void command_loop(Hall event[])
{
        string action;

         do {
                cin >> action;

                if (action == "RQ") {
                        do_rq(event);
                } else if (action == "PR") {
                        do_pr(event);
                } else if (action == "CA") {
                        do_ca(event);
                }
        } while (action != "QU");
        return;
}

// do_rq
//      purpose: figure out wich day the request is for and provide an error
//               message if it fails
//      arguments: array of halls
//      returns: void
//      effects: calls the request function in the Hall class for the specified
//               day
//      notes: uses string2int as a converter

void do_rq(Hall event[])
{
        string action, name, type, day;
        int num, day_num;
        bool done = false;

        cin >> name >> num >> type >> day;

        if (day == "any") {
                for (int x = 0; (x < EVENTS) && (done == false); x++) {
                        if (event[x].request(name, num, type, x) == true) {
                                done = true;
                        }
                }
                if (done == false) {
                        cout << "NO " << name << " not-available" << endl;
                }
        } else {
                day_num = string2int(day);
                if (event[day_num].request(name, num, type, day_num) == false) {
                        cout << "NO " << name << " not-available" << endl;
                }
        }
        return;
}

// do_pr
//      purpose: print out the Hall for a given day
//      arguments: array of Halls
//      returns: void
//      effects: figures out the day requested and then calls the appropriate
//               hall print function
//      notes: uses string2int as a converter

void do_pr(Hall event[])
{
        string day;
        int day_num;
        
        cin >> day;
        
        if (day == "all") {
                for (int x = 0; x < EVENTS; x++) {
                        event[x].print();
                }
        } else {
                day_num = string2int(day);
                event[day_num].print();
        }
        return;
}

// do_ca
//      purpose: cancel a request in the Hall for the specified day
//      arguments: array of halls
//      returns: void
//      effects: calls the cancel function for that hall, outputs and error if 
//               that function fails

void do_ca(Hall event[])
{
        string name, day;
        int day_num;
                
        cin >> name >> day;
        day_num = string2int(day);
        if (event[day_num].cancel(name) == true) {
                cout << "OK " << name << " cancelled" << endl;
        } else {
                cout << "NO " << name << " no-reservation";
                                cout << endl;            
        }
        return;
}
                        
                                
                
