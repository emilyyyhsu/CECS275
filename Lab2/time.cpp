/* 
* Program displays inputted number of milliseconds as days, 
* hours, minutes, seconds, and milliseconds
* @author Emily Hsu
* Version 0.0.0
* Created 9/2/2025
* Last modified 9/3/2025, 6:21 PM PST
*/

#include <iostream> 
#include <iomanip>

using namespace std;

int main() {
    const int milliseconds_per_day = 86400000,     // Number of milliseconds in a day
    milliseconds_per_hour = 3600000,               // Number of milliseconds in an hour
    milliseconds_per_minute = 60000,               // Number of milliseconds in a minute
    milliseconds_per_second = 1000;                // Number of milliseconds in a second
    
    // Define variables to store large integer values
    long long userTime, days, daysToMilliseconds, hours, hoursToMilliseconds, 
    minutes, minutesToMilliseconds, seconds, secondsToMilliseconds, milliseconds;
    
    // Prompt user to enter amount of time and store in variable userTime
    cout << "Please enter the number of milliseconds: ";
    cin >> userTime;

    // Calculate the number of days 
    days = (userTime - (userTime % milliseconds_per_day))/milliseconds_per_day;
    // Number of days from userTime as milliseconds 
    daysToMilliseconds = days * milliseconds_per_day;

    // Calculate the number of hours 
    hours = (userTime - daysToMilliseconds)/milliseconds_per_hour;
    // Number of hours from userTime as milliseconds 
    hoursToMilliseconds = hours*milliseconds_per_hour;

    // Calculate the number of minutes 
    minutes = (userTime - daysToMilliseconds - hoursToMilliseconds)/milliseconds_per_minute;
    // Number of minutes from userTime as milliseconds 
    minutesToMilliseconds = minutes*milliseconds_per_minute;

    // Calculate the number of seconds
    seconds = (userTime - daysToMilliseconds - hoursToMilliseconds - minutesToMilliseconds)/10;

    // Print statement displaying the inputted time as milliseconds and the time converted 
    // into days, hours, minutes, seconds, and milliseconds
    cout << userTime << " ms = " 
    <<  setw(2) << setfill('0') << days << "d "             // Set the field width to 2 to allow for a '0' 
    <<  setw(2) << setfill('0') << hours << ":"             // to be inserted in front of each value
    <<  setw(2) << setfill('0') << minutes << ":" 
    <<  std::fixed << std::setprecision(2) << seconds << endl;
    
    return 0;

}