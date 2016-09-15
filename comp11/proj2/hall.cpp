// Definition of a Hall class
//
// James McCants
// 11/12/13

#include <iostream>
#include <iomanip>

using namespace std;
//
// implementation of a Hall class
//

#include "hall.h"

//
// A constructor that sets all the initial values in the struct of seats to 
// the values of an unfilled seat
//

Hall::Hall()
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

// request
//	purpose:reads in a request and checks if it is a valid request and if   //              so calls the appropiate function based on price type
//	arguments: 2D array of struct,  number of elements
//	returns: true if succesful, else false
//	effects: does not modify the array
//	notes: has constants for request size

bool Hall::request(string custID, int num, string type, int day)
{
        bool good_rq = true;

        const int minRQ = 1;
        const int maxRQ = 12;

        if (check_ID(custID) == true) {                  
                return false;
        }
        if ((num < minRQ) || (num > maxRQ)) {
                cout << "NO " << custID;
                cout << " bad-number" << endl;
                good_rq = false;
        }
        if ((good_rq == true) && (type == "hi")) {
                if (hi_consec(custID, num, day) == false) {
                        return false;
                }
        } else if ((good_rq == true) && (type == "lo")) {
                if (lo_consec_l(custID, num, day) == false) {
                        return false;
                }
        } else if ((good_rq == true) && (type == "any")) {
                if (any_avail(custID, num, day) == false) {
                        return false;
                }
        }
        return true;
}

// cancel
//       purpose: searches for a name in the array and whenever it finds it     //                replaces the info to the intial values as put in the intialize//                function, prints out when it is done
//       arguments: 2D array of struct, name, number of elements
//       returns: true if succesful, else false
//       effects: removes an order from the venue

bool Hall::cancel(string custID)
{
        int row = 0;
        int seat = 0;

        if (check_ID(custID) == false) {
                return false;
        }

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
        return true;
}

// print
//	purpose: prints out the array
//	arguments: 2D array of struct, number of elements
//	returns: void
//	effects: does not modify the array
//	notes: array should be filled with things other than dead squirrels

void Hall::print()
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

// check_ID
//       purpose: checks if a name has already been used in the array
//       arguments: 2D array of struct, name, number of elements
//       returns: true if the name is there, else false
//       effects: does not change the array

bool Hall::check_ID(string custID)
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

void Hall::report_order(string custID, int day)
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
        cout << day << " ";
        
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

// hi_consec
//	purpose: fills seats for people who requested type hi, checks all       //               rows to try and find enough seats in a single row for the party//               before calling another function to put them anywhere it can in //               hi, if sucessful calls a function that prints out info
//	argumnets: 2D array of structs, number of seats requested, name,        //                 number of elements
//	returns: true if it or hi_non is sucessful, else false
//	effects: fills seats with name, sets them as full, sets price as high
//               with no discount

bool Hall::hi_consec(string custID, int num_rq, int day)
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
                report_order(custID, day);
        }
        if ((done == true) || ((hi_non(custID, num_rq, day)) == true)) {
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

bool Hall::hi_non(string custID, int num_rq, int day)
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
                report_order(custID, day);
                return true;
        } else {
                return false;
        }
}

// lo_consec_l
//	purpose: fills seats for people who requested type lo in the top section//               of the venue on the left side of the high priced area, if      //               there aren't enough consecutive seats, then it calls a function//               to check the right side
//	argumnets: 2D array of structs, number of seats requested, name,        //                 number of elements and day
//	returns: true if it or lo_consec_r or lo_consec_b or lo_non_avail is    //               sucessful, else false
//	effects: fills seats with name, sets them as full, sets price as low
//               with no discount or calls low_consec_r
        
bool Hall::lo_consec_l(string custID, int num_rq, int day)
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
                report_order(custID, day);
        }
        if ((done == true) || (lo_consec_r(custID, num_rq, day) == true)) { 
                return true;
        } else {
                return false;
        }
}

// lo_consec_r
//	purpose: fills seats for people who requested type lo in the top section//               of the venue on the right side of the high priced area, if     //               there aren't enough consecutive seats, then it calls a function//               to check the bottom section
//	argumnets: 2D array of structs, number of seats requested, name,        //                 number of elements
//	returns: true if it or lo_consec_b or lo_non_avail is sucessful, else   //               false
//	effects: fills seats with name, sets them as full, sets price as low
//               with no discount or calls lo_consec_b

bool Hall::lo_consec_r(string custID, int num_rq, int day)
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
                report_order(custID, day);
        }
        if ((done == true) || (lo_consec_b(custID, num_rq, day) == true)) {
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

bool Hall::lo_consec_b(string custID, int num_rq, int day)
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
                report_order(custID, day);
        }
        if ((done == true) || (lo_non_avail(custID, num_rq, day) == true)) {
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

bool Hall::lo_non_avail(string custID, int num_rq, int day)
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
                lo_non_fill(custID, num_rq, day);
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

void Hall::lo_non_fill(string custID, int num_rq, int day)
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
        report_order(custID, day);
        return;
}

// any_avail
//       purpose: checks to see if hi_consec works, if not checks if any_consec //       works, if not checks if lo_consec works, if not checks if there are    //       enough seats available in the array anywhere to fill the seats         //       requested.
//       arguments: 2D array of struct, name, num_rq, number of elements
//       return: true if any of above functions are sucessful or if there are   //               enough seats for any_non_fill to run, else false
//       effects: fills out the array for requests of price type 'any'

bool Hall::any_avail(string custID, int num_rq, int day)
{
        int row = 0;
        int seat = 0;
        int count_avail = 0;
        bool done = false;

        if ((hi_consec(custID, num_rq, day) == true) ||
            (any_consec(custID, num_rq, day) == true) ||
            (lo_consec_r(custID, num_rq, day) == true)) {
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
                any_non_fill(custID, num_rq, day);
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

bool Hall::any_consec(string custID, int num_rq, int day)
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
                report_order(custID, day);
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

void Hall::any_non_fill(string custID, int num_rq, int day)
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
        report_order(custID, day);
        return;
}
