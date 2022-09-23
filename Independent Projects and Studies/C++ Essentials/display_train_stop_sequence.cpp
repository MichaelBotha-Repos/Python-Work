/**************************************************************
 * 
 * hghghghhghghghhghhhg
 * 
 * ************************************************************/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int stop_count = 0;

struct TRAIN_STATION
{
    string name = "";
    bool stop = false;
};

int main(int argc, char * argv[])
{
    struct TRAIN_STATION all_stations[20];  // Assume a max of 20 stops 
    ifstream text_file;
    int number_of_stations = 0, number_of_stops = 0;
    char file_char;
    string stopping_stations[20], express_stations[20];

    if(argc >2) 
    {
        cout << "You have entered too many arguments";
        text_file.close();
        return 0;
    }
    else
    {
        text_file.open(argv[1]);
        if(text_file.fail() == true)
        {
            cout << "You have entered an incorrect path or path format";
            text_file.close();
            return 0;
        }
    }

    int comma_count = 0, bool_ready_flag = 0;
    string is_stop = "";
    while(!text_file.eof())
    {   
        text_file.get(file_char); //read single character
        if(text_file.eof())
        {
            file_char = '\n';
            text_file.close();
        }

        if(file_char == ',') //check for the "," delimiter
        {
            ++comma_count;
            continue;
        }
        else if(file_char == ' ' && comma_count == 1)
        {
            bool_ready_flag = 1;
            continue;
        }
        // Ensure that the character is a capital/lowercase letter, an apostraphe, hyphen, or space
        // which are valid name characters
        if(bool_ready_flag == 0 && 
            (   
                (file_char > 64 && file_char < 90) || 
                (file_char > 96 && file_char < 123) || 
                (file_char == '-')|| 
                (file_char == '\'') ||
                (file_char == ' ')
            )   
        )
        {
            all_stations[number_of_stations].name += file_char; //conacatenate char to station name in appropriate struct
        }
        else if(bool_ready_flag == 1)
        {
            if( 
                file_char == 'F' ||
                file_char == 'a' ||
                file_char == 'l' ||
                file_char == 's' ||
                file_char == 'e' ||
                file_char == 'T' ||
                file_char == 'r' ||
                file_char == 'u' 
              )
            {
                is_stop += file_char;
            }
            else if(file_char == ' ')
            {
                continue;
            }
            else if(file_char == '\n')
            {    
                if(is_stop == "True")
                {
                    all_stations[number_of_stations].stop = true;
                }
                else if(is_stop == "False")
                {
                    all_stations[number_of_stations].stop = false;
                }
                else
                {
                    cout << "Incorrect format in text - false/true not correct format";
                    return 1;
                }
                is_stop.clear();
                comma_count--;
                ++number_of_stations;
                bool_ready_flag = 0;
            }
            else
            {
                cout<< "incorrect Boolean format";
                text_file.close();
                return 0;
            }
        }
        else
        {   
            if(file_char == '\n' && text_file.eof())
            {
                break;
            }
            else
            {
                cout << "Incorrect format in text";
                text_file.close();
                return 0;
            } 
        }
    }
    // **check current station did not just have spaces after without a comma
    int stop_number = 0, express_number = 0;
    for(int i=0; i < number_of_stations; i++)
    {
        cout << endl << all_stations[i].name << "--->" << all_stations[i].stop;

        if(all_stations[i].stop == true)
        {
            number_of_stops ++;
            stopping_stations[stop_number] = all_stations[i].name;
            stop_number++;
        }
        else
        {
            express_stations[express_number] = all_stations[i].name;
        }

    }

    if(number_of_stations == 2)
    {
        cout << "\nThis train stops at " << stopping_stations[0] << " and " << stopping_stations[1] << " only";
    }
    else if(number_of_stations == number_of_stops)
    {
        cout << "\nThis train stops at all stations";

    }
    else if( number_of_stops == (number_of_stations-1))
    {
        cout << "\nThis train stops at all stations except " << express_stations[0];
    }

    return 0;
}