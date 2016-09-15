//                          Concert Ticket Server
//
// The purpose of this program is to read in requests from potential customers
// for concert tickets and to sell them seats at a venue with 14 rows (A-N)
// and 20 seats (1-20) per row. There are higher priced seats ($200) in rows
// A-H seats 5-16. The rest of the seats are cheaper ($150). There is a discount
// of 10% if the buyer's party is split up. The program also prints out a map
// of the venue on request. The maximum number of tickets that can be requested
// is 12. The customer can request seats of price type hi, lo, or any. The
// program is designed to maximize profit.
//
// James McCants
// 10/29/13
//

# include <iostream>
# include <iomanip>

using namespace std;

// size of seating area
const int          ROWS = 14;
const int SEATS_PER_ROW = 20;

// size of high price area
const int HIGH_SEAT_START = 4;   
const int HIGH_SEAT_END   = 15; 
const int HIGH_ROW_END    = 8;  

// prices
const double HIGH_PRICE = 200.00;
const double LOW_PRICE  = 150.00;
const double DISCOUNT   = 0.9;

// Definition of a seat
        struct seat_info {
                string name;
                double price;
                char row_letter;
                int seat_num;
                bool filled;
                bool discount;
        };

//Operations
void print       (seat_info chart[ROWS][SEATS_PER_ROW]);
void cancel      (seat_info chart[ROWS][SEATS_PER_ROW]);
bool hi_consec   (seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
bool hi_non      (seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
bool lo_consec_r (seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
bool lo_consec_l (seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
bool lo_consec_b (seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
bool lo_non_avail(seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
void lo_non_fill (seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
bool any_avail   (seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
void any_non_fill(seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);
bool any_consec  (seat_info chart[ROWS][SEATS_PER_ROW],
                  string custID, int seats_rq);

//Utilities
void command_loop(seat_info chart[ROWS][SEATS_PER_ROW]);    
void fill_seats  (seat_info chart[ROWS][SEATS_PER_ROW]);
void process_rq  (seat_info chart[ROWS][SEATS_PER_ROW]);
void report_order(seat_info chart[ROWS][SEATS_PER_ROW], string custID);
bool check_ID    (seat_info chart[ROWS][SEATS_PER_ROW], string custID);

// main
//	purpose: declare the array and call the utility functions
//	argumnets: 2D array of struct, number of elements
//	returns: 0
//	effects: sets up the array
//	notes: calls the array using global constants

int main()
{
        seat_info chart[ROWS][SEATS_PER_ROW];     //declares the array

        fill_seats(chart);            //initializes the venue with empty seats
        command_loop(chart);          //awaits input from the user
        
        return 0;                     //signals the end of the program
}

// fill_seats
//	purpose: fill the array with empty seats
//	arguments: 2D array of struct, number of elements
//	returns: void
//	effects: changes the contents of the array to have empty seats and no	//               price value also defines each seat with a row letter and seat
//               number

void fill_seats(seat_info chart[][SEATS_PER_ROW])
{
        int row = 0;
        int seat = 0;
        char a = 'A';

        while (row < ROWS) {
                while (seat < SEATS_PER_ROW) {
                        chart[row][seat].name = "---";
                        chart[row][seat].price = 0.00;
                        chart[row][seat].row_letter = a;
                        chart[row][seat].seat_num = seat + 1;
                        chart[row][seat].filled = false;
                        chart[row][seat].discount = false;
                        seat++;
                }
                row++;
                a++;                 //incriments the row letter
                seat = 0;
        }
}

// command_loop
//	purpose: read in a command from the user and call the correct function  //               and loop until the user quits
//	arguments: 2D array of struct, number of elements
//	returns: void
//	effects: does not modify the array
//	notes: input must be a valid command (RQ, PR, CA, QU). Runs until user
//             quits with 'QU'

void command_loop(seat_info chart[][SEATS_PER_ROW])
{
        string action;
        
        do {
                cin >> action;
                
                if (action == "RQ") {
                        process_rq(chart);
                } else if (action == "PR") {
                        print(chart);
                } else if (action == "CA") {
                        cancel(chart);
                }
        } while (action != "QU");
        return;
}

// print
//	purpose: prints out the array
//	arguments: 2D array of struct, number of elements
//	returns: void
//	effects: does not modify the array
//	notes: array should be filled with things other than dead squirrels

void print(seat_info chart[][SEATS_PER_ROW])
{

        int row = 0;
        int seat = 0;
        double money = 0.00;
        int num_spaces = 1;

        while (row < ROWS) {
                while (seat < SEATS_PER_ROW) {
                        cout << chart[row][seat].name;    //prints name
                        if (num_spaces < SEATS_PER_ROW) { 
                                cout << " ";
                        } else {
                                cout << endl;             //removes extra space
                        }
                        num_spaces++;
                        money += chart[row][seat].price;  //tallies money spent
                        seat++;
                }
                row++;
                seat = 0;
                num_spaces = 1;                           //resets spaces
        }
        cout << setprecision(2) << fixed;                 //prints decimals
        cout << "Revenue: " << money << endl;
        return;
}

// request
//	purpose:reads in a request and checks if it is a valid request and if   //              so calls the appropiate function based on price type
//	arguments: 2D array of struct,  number of elements
//	returns: void
//	effects: does not modify the array
//	notes: has constants for request size

void process_rq(seat_info chart[][SEATS_PER_ROW])
{
        int num_seats_rq;
        bool good_rq = true;
        string custID, type;

        const int minRQ = 1;
        const int maxRQ = 12;

        cin >> custID >> num_seats_rq >> type; //takes in name, num seats rq,
                                               //and price type

        if (check_ID(chart, custID) == true) {                  
                cout << "NO " << custID;
                cout << " already-reserved" << endl;
                good_rq = false;
        }
        if ((num_seats_rq < minRQ) || (num_seats_rq > maxRQ)) {
                cout << "NO " << custID;
                cout << " bad-number" << endl;
                good_rq = false;
        }
        if ((good_rq == true) && (type == "hi")) {
                if (hi_consec(chart, custID, num_seats_rq) == false) {
                        cout << "NO " << custID << " not-available" << endl;
                }
        } else if ((good_rq == true) && (type == "lo")) {
                if (lo_consec_r(chart, custID, num_seats_rq) == false) {
                        cout << "NO " << custID << " not-available" << endl;
                }
        } else if ((good_rq == true) && (type == "any")) {
                if (any_avail(chart, custID, num_seats_rq) == false) {
                        cout << "NO " << custID << " not-available" << endl;
                }
        }
        return;
}

// hi_consec
//	purpose: fills seats for people who requested type hi, checks all       //               rows to try and find enough seats in a single row for the party//               before calling another function to put them anywhere it can in //               hi, if sucessful calls a function that prints out info
//	argumnets: 2D array of structs, number of seats requested, name,        //                 number of elements
//	returns: true if it or hi_non is sucessful, else false
//	effects: fills seats with name, sets them as full, sets price as high
//               with no discount

bool hi_consec(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{        
        int row = 0;
        int seat = HIGH_SEAT_START;
        int count_empty = 0;
        bool done = false;

        while ((row < HIGH_ROW_END) && (done == false)) {
                while ((seat <= HIGH_SEAT_END) && (count_empty < num_rq)) {
                        if (chart[row][seat].filled == false) {
                                count_empty++;
                        }
                        if ((count_empty > 0) &&
                            (chart[row][seat].filled == true)) {
                                count_empty = 0;
                        }
                        seat++;
                }
                seat--;
                if (count_empty == num_rq) {
                        while (count_empty > 0) {
                                chart[row][seat].filled = true;
                                chart[row][seat].name = custID;
                                chart[row][seat].price = HIGH_PRICE;
                                count_empty--;
                                seat--;
                        }
                        done = true;
                }
                if (done != true) {
                        row++;
                        count_empty = 0;
                        seat = HIGH_SEAT_START;
                }
        }
        if (done == true) {
                report_order(chart, custID);
        }
        if ((done == true) || ((hi_non(chart, custID, num_rq)) == true)) {
        return true;
        } else {
                return false;
        }
}

// hi_non
//	purpose: fills seats for people who requested type hi and there are not //               enough consecutive seats for their party but are enough        //               avaialble otherwise
//	argumnets: 2D array of structs, number of seats requested, name,        //                 number of elements
//	returns: true if it is sucessful, else false
//	effects: fills seats with name, sets them as full, sets price as high
//               with discount

bool hi_non(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{
        int row = 0;
        int seat = HIGH_SEAT_START;
        int count_avail = 0;
        bool done = false;

        while ((row < HIGH_ROW_END) && (done == false)) {
                while ((seat <= HIGH_SEAT_END) && (count_avail < num_rq)) {
                        if (chart[row][seat].filled == false) {
                                count_avail++;
                        }
                        seat++;
                }
                row++;
                seat = HIGH_SEAT_START;
                if (count_avail == num_rq) {
                        done = true;
                }
        }
        row = 0;
        
        while ((row < HIGH_ROW_END) && (done == true)) {
                while ((seat <= HIGH_SEAT_END) && (count_avail > 0)) {
                        if (chart[row][seat].filled == false) {
                                chart[row][seat].name = custID;
                                chart[row][seat].filled = true;
                                chart[row][seat].price = HIGH_PRICE;
                                chart[row][seat].discount = true;
                                count_avail--;
                        }
                        seat++;
                }
                row++;
                seat = HIGH_SEAT_START;
        }
        if (done == true) {
                report_order(chart, custID);
                return true;
        } else {
                return false;
        }
}

// lo_consec_r
//	purpose: fills seats for people who requested type lo in the top section//               of the venue on the right side of the high priced area, if     //               there aren't enough consecutive seats, then it calls a function//               to check the left side
//	argumnets: 2D array of structs, number of seats requested, name,        //                 number of elements
//	returns: true if it or lo_consec_l or lo_consec_b or lo_non_avail is    //               sucessful, else false
//	effects: fills seats with name, sets them as full, sets price as low
//               with no discount or calls low_consec_l

bool lo_consec_r(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{
        int row = 0;
        int seat = 0;
        int count_empty = 0;
        bool done = false;

        while ((row < HIGH_ROW_END) && (done == false)) {
                while ((seat < HIGH_SEAT_START) && (count_empty < num_rq)) {
                        if (chart[row][seat].filled == false) {
                                count_empty++;
                        }
                        if ((count_empty > 0) &&
                            (chart[row][seat].filled == true)) {
                                count_empty = 0;
                        }
                        seat++;
                }
                seat--;
                if (count_empty == num_rq) {
                        while (count_empty > 0) {
                                chart[row][seat].filled = true;
                                chart[row][seat].name = custID;
                                chart[row][seat].price = LOW_PRICE;
                                count_empty--;
                                seat--;
                        }
                        done = true;
                }
                if (done != true) {
                        row++;
                        count_empty = 0;
                        seat = 0;
                }
        }
        if (done == true) {
                report_order(chart, custID);
        }
        if ((done == true) || (lo_consec_l(chart, custID, num_rq) == true)) { 
                return true;
        } else {
                return false;
        }
}

// lo_consec_l
//	purpose: fills seats for people who requested type lo in the top section//               of the venue on the left side of the high priced area, if      //               there aren't enough consecutive seats, then it calls a function//               to check the bottom section
//	argumnets: 2D array of structs, number of seats requested, name,        //                 number of elements
//	returns: true if it or lo_consec_b or lo_non_avail is sucessful, else   //               false
//	effects: fills seats with name, sets them as full, sets price as low
//               with no discount or calls lo_consec_b

bool lo_consec_l(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{
        int row = 0;
        int seat = (HIGH_SEAT_END + 1);
        int count_empty = 0;
        bool done = false;

        while ((row < HIGH_ROW_END) && (done == false)) {
                while ((seat < SEATS_PER_ROW) && (count_empty < num_rq)) {
                        if (chart[row][seat].filled == false) {
                                count_empty++;
                        }
                        if ((count_empty > 0) &&
                            (chart[row][seat].filled == true)) {
                                count_empty = 0;
                        }
                        seat++;
                }
                seat--;
                if (count_empty == num_rq) {
                        while (count_empty > 0) {
                                chart[row][seat].filled = true;
                                chart[row][seat].name = custID;
                                chart[row][seat].price = LOW_PRICE;
                                count_empty--;
                                seat--;
                        }
                        done = true;
                }
                if (done != true) {
                        row++;
                        count_empty = 0;
                        seat = (HIGH_SEAT_END + 1);
                }
        }
        if (done == true) {
                report_order(chart, custID);
        }
        if ((done == true) || (lo_consec_b(chart, custID, num_rq) == true)) {
                return true;
        }else {
                return false;
        }
}

// lo_consec_b
//      purpose: fills seats for people who requested type lo in the bottom     //               section of the venue if there are enough consecutive seats,    //               else calls a function that checks for non-consecutive seats
//	argumnets: 2D array of structs, number of seats requested, name,        //                 number of elements
//	returns: true if it or lo_non_avail is sucessful, else false
//	effects: fills seats with name, sets them as full, sets price as low
//               with no discount or calls lo_non_avail

bool lo_consec_b(seat_info chart [][SEATS_PER_ROW], string custID, int num_rq)
{
        int row = HIGH_ROW_END;
        int seat = 0;
        int count_empty = 0;
        bool done = false;

        while ((row < ROWS) && (done == false)) {
                while ((seat < SEATS_PER_ROW) && (count_empty < num_rq)) {
                        if (chart[row][seat].filled == false) {
                                count_empty++;
                        }
                        if ((count_empty > 0) &&
                            (chart[row][seat].filled == true)) {
                                count_empty = 0;
                        }
                        seat++;
                }
                seat--;
                if (count_empty == num_rq) {
                        while (count_empty > 0) {
                                chart[row][seat].filled = true;
                                chart[row][seat].name = custID;
                                chart[row][seat].price = LOW_PRICE;
                                count_empty--;
                                seat--;
                        }
                        done = true;
                }
                if (done != true) {
                        row++;
                        count_empty = 0;
                        seat = 0;
                }
        }
        if (done == true) {
                report_order(chart, custID);
        }
        if ((done == true) || (lo_non_avail(chart, custID, num_rq) == true)) {
                return true;
        } else {
                return false;
        }
}

// lo_non_avail
//       purpose: checks to see if there are enough available seats for the     //       number requested anywhere in the low section, if there are it calls    //       lo_non_fill to fill them
//       arguments: 2D array of struct, name, number of seats,                  //                  number of elements
//       returns: true if there are enough, else false
//       effects: checks availability, doesn't change anything, calls           //                lo_non_fill if necessary

bool lo_non_avail(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{    
        int row = 0;
        int seat = 0;
        int count_avail = 0;
        bool done = false;

        while ((row < HIGH_ROW_END) && (done == false)) {
                while (((seat < HIGH_SEAT_START) ||
                        ((seat > HIGH_SEAT_END) &&
                         (seat < SEATS_PER_ROW))) &&
                       (count_avail < num_rq)) {                                                        if (chart[row][seat].filled == false) {
                                count_avail++;
                        }
                        if (seat == (HIGH_SEAT_START - 1)) {
                                seat += ((HIGH_SEAT_END + 1) -
                                         (HIGH_SEAT_START - 1));
                        } else {
                                seat++;
                        }
                }
                row++;
                seat = 0;
                if (count_avail == num_rq) {
                        done = true;
                }
        }
        while (((row >= HIGH_ROW_END) && (row < ROWS)) && (done == false)) {
                while ((seat < SEATS_PER_ROW) && (count_avail < num_rq)) {
                        if (chart[row][seat].filled == false) {
                                count_avail++;
                        }
                        seat++;
                }
                row++;
                seat = 0;
                if (count_avail == num_rq) {
                        done = true;
                }
        }
        if (done == true) {
                lo_non_fill(chart, custID, num_rq);
        }
        if (done == true) {
                return true;
        } else {
                return false;
        }
}

// lo_non_fill
//	purpose: fills seats for people who requested type lo and there are not //               enough consecutive seats for their party but there are enough  //               available seprately
//	argumnets: 2D array of structs, number of seats requested, name,                           number of elements
//	returns: true if it is sucessful, else false
//	effects: fills seats with name, sets them as full, sets price as low
//               with discount

void lo_non_fill(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{
        int row = 0;
        int seat = 0;
        bool done = false;

        while ((row < HIGH_ROW_END) && (done == false)) {
                while (((seat < HIGH_SEAT_START) ||
                        ((seat > HIGH_SEAT_END) &&
                         (seat < SEATS_PER_ROW))) &&
                       (num_rq > 0)) {                            
                        if (chart[row][seat].filled == false) {
                                chart[row][seat].name = custID;
                                chart[row][seat].filled = true;
                                chart[row][seat].price = LOW_PRICE;
                                chart[row][seat].discount = true;
                                num_rq--;
                        }
                        if (seat == (HIGH_SEAT_START - 1)) {
                                seat += ((HIGH_SEAT_END + 1) -
                                         (HIGH_SEAT_START - 1));
                        } else {
                                seat++;
                        }
                }
                row++;
                seat = 0;
                if (num_rq == 0) {
                        done = true;
                }
        }
        while (((row >= HIGH_ROW_END) && (row < ROWS)) && (done == false)) {
                while ((seat < SEATS_PER_ROW) && (num_rq > 0)) {
                        if (chart[row][seat].filled == false) {
                                chart[row][seat].name = custID;
                                chart[row][seat].filled = true;
                                chart[row][seat].price = LOW_PRICE;
                                chart[row][seat].discount = true;
                                num_rq--;
                        } 
                        seat++;
                }
                row++;
                seat = 0;
                if ( num_rq == 0) {
                        done = true;
                }
        }
        report_order(chart, custID);
        return;
}
 
// any_avail
//       purpose: checks to see if hi_consec works, if not checks if any_consec //       works, if not checks if lo_consec works, if not checks if there are    //       enough seats available in the array anywhere to fill the seats         //       requested.
//       arguments: 2D array of struct, name, num_rq, number of elements
//       return: true if any of above functions are sucessful or if there are   //               enough seats for any_non_fill to run, else false
//       effects: fills out the array for requests of price type 'any'

bool any_avail(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{
        int row = 0;
        int seat = 0;
        int count_avail = 0;
        bool done = false;

        if ((hi_consec(chart, custID, num_rq) == true) ||
            (any_consec(chart, custID, num_rq) == true) ||
            (lo_consec_r(chart, custID, num_rq) == true)) {
                return true;
        }
 
        while ((row < ROWS) && (done == false)) {
                while ((seat < SEATS_PER_ROW) && (count_avail < num_rq)) {
                        if (chart[row][seat].filled == false) {
                                count_avail++;
                        }
                        seat++;
                }
                row++;
                seat = 0;
                if (count_avail == num_rq) {
                        done = true;
                }
        }
        if (done == true) {
                any_non_fill(chart, custID, num_rq);
                return true;
        } else {
                return false;
        }
}

// any_consec
//       purpose: checks if there are enough empty seats in a row for           //                consecutive seating for price type 'any' and then fills in    //                if there are
//       arguments: 2D array of struct, name, num of requests, number of        //                  elements
//       return: true if it fills seats, else false
//       effects: fills seats with price type 'any' consecutively

bool any_consec(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{
        int row = 0;
        int seat = 0;
        int count_empty = 0;
        bool done = false;

        while ((row < ROWS) && (done == false)) {
                while ((seat < SEATS_PER_ROW) && (count_empty < num_rq)) {
                        if (chart[row][seat].filled == false) {
                                count_empty++;
                        }
                        if ((count_empty > 0) &&
                            (chart[row][seat].filled == true)) {
                                count_empty = 0;
                        }
                        seat++;
                }
                seat--;
                if (count_empty == num_rq) {
                        while (count_empty > 0) {
                                if ((row < HIGH_ROW_END) &&
                                    (seat >= HIGH_SEAT_START) &&
                                    (seat <= HIGH_SEAT_END)) {
                                        chart[row][seat].price = HIGH_PRICE;
                                } else {
                                        chart[row][seat].price = LOW_PRICE;
                                }
                                chart[row][seat].filled = true;
                                chart[row][seat].name = custID;
                                count_empty--;
                                seat--;
                        }
                        done = true;
                }
                if (done != true) {
                        row++;
                        count_empty = 0;
                        seat = 0;
                }
        }
        if (done == true) {
                report_order(chart, custID);
                return true;
        } else {
        return false;
        }
}

// any_non_fill
//       purpose: fills in empty seats for price type 'any' non consecutively   //                after they are checked for availability in any_avail, checks  //                where they are in the array for the price that they should be
//       arguments: 2D array of struct, name, number of elements, num requested
//       return: void
//       effect: fills in seats of price type any non consecutively

void any_non_fill(seat_info chart[][SEATS_PER_ROW], string custID, int num_rq)
{
        int row = 0;
        int seat = 0;
        bool done = false;

        while ((row < ROWS) && (done == false)) {
                while ((seat < SEATS_PER_ROW) && (num_rq > 0)) {
                        if (chart[row][seat].filled == false) {
                                if ((row < HIGH_ROW_END) &&
                                    (seat >= HIGH_SEAT_START) &&
                                    (seat <= HIGH_SEAT_END)) {
                                        chart[row][seat].price = HIGH_PRICE;
                                } else {
                                        chart[row][seat].price = LOW_PRICE;
                                }
                                chart[row][seat].filled = true;
                                chart[row][seat].name = custID;
                                chart[row][seat].discount = true;
                                num_rq--;
                        }
                        seat++;
                }
                row++;
                seat = 0;
                if (num_rq == 0) {
                        done = true;
                }
        }
        report_order(chart, custID);
        return;
}

// check_ID
//       purpose: checks if a name has already been used in the array
//       arguments: 2D array of struct, name, number of elements
//       returns: true if the name is there, else false
//       effects: does not change the array

bool check_ID(seat_info chart [][SEATS_PER_ROW], string custID)
{
        int row = 0;
        int seat = 0;

        while (row < ROWS) {
                while (seat < SEATS_PER_ROW) {
                        if (chart[row][seat].name == custID) {
                                return true;
                        }
                        seat++;
                }
                seat = 0;
                row++;
        }
        return false;
}

// report_order
//       purpose: to print out the details of a sucessful order for a customer
//       arguments: 2D array of struct, name, number of elements
//       returns: void
//       effects: does not change anything

void report_order(seat_info chart[][SEATS_PER_ROW], string custID)
{
        int row = 0;
        int seat = 0;
        int price = 0;
        int num_tics = 0;
        int num_spaces = 1;

        while (row < ROWS) {
                while (seat < SEATS_PER_ROW) {
                        if (chart[row][seat].name == custID) {
                                if (chart[row][seat].discount == true) {
                                        price +=
                                        (DISCOUNT * chart[row][seat].price);
                                } else {
                                        price += chart[row][seat].price;
                                }
                                num_tics++;
                        }
                        seat++;
                }
                row++;
                seat = 0;
        }
        cout << "OK " << custID << " " << price << " " << num_tics << " ";
        
        row = 0;
        seat = 0;

        while (row < ROWS) {
                while (seat < SEATS_PER_ROW) {
                        if (chart[row][seat].name == custID) {
                                cout << chart[row][seat].row_letter;
                                cout << chart[row][seat].seat_num;
                                if (num_spaces < num_tics) {
                                        cout << " ";
                                } else {
                                        cout << endl;
                                }
                                num_spaces++;
                        }
                        seat++;
                }
                seat = 0;
                row++;
        }
        return;
}

// cancel
//       purpose: searches for a name in the array and whenever it finds it     //                replaces the info to the intial values as put in the intialize//                function, prints out when it is done
//       arguments: 2D array of struct, name, number of elements
//       returns: void
//       effects: removes an order from the venue

void cancel(seat_info chart[][SEATS_PER_ROW])
{
        int row = 0;
        int seat = 0;
        string custID;

        cin >> custID;

        while (row < ROWS) {
                while (seat < SEATS_PER_ROW) {
                        if (chart[row][seat].name == custID) {
                                chart[row][seat].name = "---";
                                chart[row][seat].price = 0.00;
                                chart[row][seat].filled = false;
                        }
                        seat++;
                }
                row++;
                seat = 0;
        }
        
        cout << "OK " << custID << " cancelled" << endl;
                       
        return;
}

                
                    
                
