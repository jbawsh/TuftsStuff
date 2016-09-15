// Header file for a Hall class
//
// James McCants
// 11/12/13

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

// days
const int EVENTS = 7;

class Hall
{
 public:
        // a constructor for a hall, sets to unfilled values
        Hall();

        // proccesses a users request
        bool request(string name, int num, string type, int day);

        // proccesses a cancel
        bool cancel(string name);

        // prints out the hall
        void print();

 private:
        // Definition of a seat
        struct seat_info
        {
                string name;
                double price;
                char row_letter;
                int seat_num;
                bool filled;
                bool discount;
        };
        // Declaration of seating chart
        seat_info chart[ROWS][SEATS_PER_ROW];

        // Operations
        
        // checks for high priced seats consecutively
        bool hi_consec   (string custID, int seats_rq, int day);

        // checks for high priced seats non-consecutively
        bool hi_non      (string custID, int seats_rq, int day);

        // checks for low priced seats consecutively on the left side of the            // low priced seating area
        bool lo_consec_l (string custID, int seats_rq, int day);

        // checks for low priced seats consecutively on the right side of the           // low priced seating area
        bool lo_consec_r (string custID, int seats_rq, int day);

        // checks for low priced seats consecutively on the bottome half of the         // low priced seating area
        bool lo_consec_b (string custID, int seats_rq, int day);

        // checks availability of low priced seats that are non-consecutive
        bool lo_non_avail(string custID, int seats_rq, int day);

        // fills seats of low price non-consecutively
        void lo_non_fill (string custID, int seats_rq, int day);

        // checks the availability of seats if any, non-consecutive is the              // only type left
        bool any_avail   (string custID, int seats_rq, int day);
        
        // fills in seats non-consecutively of type any
        void any_non_fill(string custID, int seats_rq, int day);

        // fills seats consecutively anywhere
        bool any_consec  (string custID, int seats_rq, int day);
        
        // Utilities

        // Reports the order once it has been filled
        void report_order(string custID, int day);

        // checks if a customer has already been entered into the chart
        bool check_ID    (string custID);
};
