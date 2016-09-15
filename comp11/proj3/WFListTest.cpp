#include <iostream>

#include "WordFreqList.h"

using namespace std;

void command_loop (void);
string get_command (void);
void prompt_for_command (void);
WFList prepend_cmd (WFList list);
void print (WFList list);
WFList empty (void);
void insertAfter_cmd (WFList list);
void set_freq_cmd (WFList list);

int main()
{
        command_loop();

        return 0;
}

void command_loop(void)
{
        string cmd;
        WFList list = empty();

        while ((cmd = get_command()) != "quit") {
                if (cmd == "print") {
                        print(list);
                        cout << endl;
                } else if (cmd == "prepend") {
                        list = prepend_cmd(list);
                } else if (cmd == "isEmpty") {
                        if (isEmpty(list))
                                cout << "yes" << endl;
                        else
                                cout << "no" << endl;
                } else if (cmd == "first" && !isEmpty(list)) {
                        cout << first(list).freq << " ";
                        cout << first(list).word << " ";
                        cout << endl;
                } else if (cmd == "rest" && !isEmpty(list)) {
                        print(list);
                        print(rest(list));
                } else if (cmd == "deleteFirst" && !isEmpty(list)) {
                        list = deleteFirst(list);
                        if (!isEmpty(list)) {
                                cout << first(list).freq << " ";
                                cout << first(list).word << " ";
                                cout << endl;
                        } else {
                                cout << "Now empty" << endl;
                        }
                } else if (cmd == "insertAfter" && !isEmpty(list)) {
                        insertAfter_cmd(list);
                } else if (cmd == "set_freq" && !isEmpty(list)) {
                        set_freq_cmd(list);
                }
        }
}

string get_command()
{
        string list;
        string cmd;

        cout << "List of commands? (y/n)" << endl;

        cin >> list;

        if (list == "y") {
                prompt_for_command();
        } else {
                cout << "Enter a command: ";
        }

        cin >> cmd;

        return cmd;
}

void prompt_for_command()
{
	cout << "  prepend      to list"       << endl
	     << "  delete       first element" << endl
	     << "  isEmpty"                    << endl
	     << "  print        the list"      << endl
	     << "  first        set of data"   << endl
             << "  rest         of the list"   << endl
             << "  deleteFirst  node"          << endl
             << "  insertAfter  node"          << endl
             << "  set_freq     of a node"     << endl   
	     << "  quit"                       << endl
	     << ":  ";
}

WFList prepend_cmd(WFList list)
{
        WordFreq new_data;
        int freq;
        string word;

        cout << "Enter a frequency to prepend: ";
        cin >> freq;
        cout << "Enter a word to prepend: ";
        cin >> word;

        new_data.freq = freq;
        new_data.word = word;

        return prepend(new_data, list);
}

void print(WFList list)
{
        if (isEmpty(list)) {
                cout << "()" << endl;
        } else {
                cout << first(list).freq << " ";
                cout << first(list).word << " ";
                cout << endl;
                print(rest(list));
        }
}

void  insertAfter_cmd(WFList list)
{
        WordFreq new_data;
        int freq;
        string word;

        cout << "Chose a frequency to insert: " << endl;
        cin >> freq;
        cout << "Chose a word to insert: " << endl;
        cin >> word;
        new_data.freq = freq;
        new_data.word = word;
        
        insertAfter(new_data, list);
        return;
}

void set_freq_cmd(WFList list)
{
        int new_freq;
        cout << "What is the new frequency you want: " << endl;
        cin >> new_freq;
        set_freq(list, new_freq);
}