// namestats.cpp -- age stats by names
//   usage: namestats name < datafile-of-year-name
// 
//  result: find avg, then range of ages and frequency by age
//  history: revised 2012-10-23 added 'who' to show_freq

#include <iostream>
#include <cstdlib>

using namespace std;


struct Person{
  int year;
  string name;
};

const int MAXPEOPLE = 50000;
const int SENTINEL  = -1;
const int NOW       = 2013;

void    read_in_data(Person person[], int sentinel, int array_size);
string  get_name    ();
void	print_ages  (Person person[], int sentinel, string who);
void    do_stats    (Person person[], int sentinel, string who);
int	find_max    (Person person[], int sentinel, string name);
int	find_min    (Person person[], int sentinel, string name);
double	find_avg    (Person person[], int sentinel, string name);
void	show_freq   (Person person[], int sentinal, string name,
                     int min, int max);

int main()
{
	Person	people[MAXPEOPLE];
	string	name;

	read_in_data(people, SENTINEL, MAXPEOPLE);
	name = get_name();
	print_ages(people, SENTINEL, name);
	do_stats(people, SENTINEL, name);

	return 0;
}

// --- read_in_data ------------------------------------------------------
//  args: array of Person structs, sentinel, max space in array
//  rets: nothing
//  does: reads from cin a year and name, puts sentinel in array
//  errs: calls exit if out of space
//
void read_in_data(Person person[], int sentinel, int space)
{
	int	yr;
	string	nm;
	int	pos = 0;

	do {
		cin >> yr >> nm ;
		if (pos >= space) {
			cerr << "Out of space\n";
			exit(1);
		}
		// TODO: add code here to store data in struct
		person[pos].year = yr;
		person[pos].name = nm;
		pos++;
	} while (yr != sentinel);
}

// --- get_name ----------------------------------------------------------
//  purp: read in one name from cin
//  args: none
//  rets: the name
string get_name()
{
  string name;
  cout << "enter a name ";
  cin >> name;
        // STUB
        return name;
}

// --- print_ages -------------------------------------------------------
//  purp: print all ages for the specified name
//  args: an array of structs, the sentinel, the name to find
//  rets: nothing
//  does: prints report to cout
//
void print_ages(Person person[], int sentinel, string who)
{
  int year = 0;
  int pos = 0;
  do {
    year = person[pos].year;
    if( who == person[pos].name ) {
      cout << 2013 - year << endl;
    }
    pos++;
  } while(year != sentinel);
        // STUB
}

// --- do_stats ----------------------------------------------------------
//  purp: compute and print avg, range AND freq for each age in range
//  args: an array of structs, the sentinel, the name to find
//  rets: nothing
//  does: prints report to cout
//
void do_stats(Person person[], int sentinel, string who)
{
	int	min, max;	// min and max age for 'who'
	double	avg;

	avg = find_avg(person, sentinel, who);
	min = find_min(person, sentinel, who);
	max = find_max(person, sentinel, who);
	cout << "average: " << avg << endl;
	cout << "range: "   << min << "-" << max << endl;
	show_freq(person, sentinel, who, min, max);
}

double find_avg(Person person[], int sent, string name)
{
  cerr << "in find_avg \n";
  int pos = 0;
  double avg;
  double total = 0;
  double counter = 0;
  int year;
 // STUB
  do {
    if(person[pos].name == name) {
      total += person[pos].year;
      counter++;
    }
    pos++;
    year = person[pos].year;
  } while(year != sent);
  avg = total/counter;
        return avg;
}

int find_min(Person person[], int sent, string name)
{
        
  int pos = 0;
  int year = 0;
  int min_year = 0;
// STUB
  do {
    year = person[pos].year;
    if(pos = 0) {
      min_year = year;
    if(year >= 0 && year <= min_year) {
      min_year = year;
    }
    pos++;
  } while(year != sent);
        return min_year;
}

int find_max(Person person[], int sent, string name)
{
        // STUB
        return -1;
}

void show_freq(Person person[], int sent, string who, int min, int max)
{
        // STUB
}
