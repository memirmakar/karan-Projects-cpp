#include <iostream>
#include <chrono>
#include <future>
#include <string>
#include <thread>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <string_view>
/*REQUIRES BOOST LIBRARIES 1.82 */

using std::string_literals::operator""s;
using std::string_view_literals::operator""sv;

class TimerAlarm {
public:
    TimerAlarm() = default;

    void setTimer();
    void setAlarm();
    void start();

private:
    void checkChro(const boost::posix_time::time_duration& chro_time);
    void checkAlarm(const boost::posix_time::ptime& al_ptime);

    char getValidChoice();

    boost::posix_time::ptime calculateAlarmDateTime(const boost::posix_time::time_duration& alarm_time);
};

void TimerAlarm::checkChro(const boost::posix_time::time_duration& chro_time) {
    std::this_thread::sleep_for(std::chrono::seconds(chro_time.total_seconds()));
    std::cout << "Time is up! "sv << "\n";
    std::cout << "DONE"sv;
}

void TimerAlarm::checkAlarm(const boost::posix_time::ptime& al_ptime) {
    while (al_ptime != boost::posix_time::second_clock::local_time()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Alarm time reached: "sv << al_ptime << "\n";
    std::cout << "DONE"sv;
}

char TimerAlarm::getValidChoice() {
    std::string input;
    char choice;

    do {
        std::cout << "Enter 'T' for timer, 'A' for alarm (a/t): ";
        std::getline(std::cin, input);

        if (input.length() == 1 && (input[0] == 'T' || input[0] == 't')) {
            choice = 'T';
        } else if (input.length() == 1 && (input[0] == 'A' || input[0] == 'a')) {
            choice = 'A';
        } else {
            std::cout << "Invalid input!\n";
        }
    } while (choice != 'T' && choice != 'A');

    return choice;
}

void TimerAlarm::setTimer() {
    int minutes;
    int seconds;
    int hour;
    std::cout << "Enter the timer hour: "sv;
    std::cin >> hour;
    std::cout << "Enter the timer minutes: "sv;
    std::cin >> minutes;
    std::cout << "Enter the timer seconds: "sv;
    std::cin >> seconds;

    boost::posix_time::time_duration chronometer_time = boost::posix_time::hours(hour) +
                                                        boost::posix_time::minutes(minutes) +
                                                        boost::posix_time::seconds(seconds);

    std::cout << "The timer will go off in "sv << boost::posix_time::second_clock::local_time() + chronometer_time << std::endl;

    std::cout << "Initial time: "sv << boost::posix_time::second_clock::local_time() << "\n";

    // Start a separate thread to check the timer
    std::future<void> alarm_future = std::async(std::launch::async, &TimerAlarm::checkChro, this, chronometer_time);
    alarm_future.wait(); // Wait for the timer thread to finish
}

boost::posix_time::ptime TimerAlarm::calculateAlarmDateTime(const boost::posix_time::time_duration& alarm_time) {
    boost::posix_time::ptime current_date_time = boost::posix_time::second_clock::local_time();

    boost::gregorian::date current_date = current_date_time.date();
    boost::gregorian::date alarm_date = current_date;

    boost::posix_time::time_duration current_time = current_date_time.time_of_day();
    if (alarm_time <= current_time) {
        alarm_date += boost::gregorian::days(1);
    }

    return boost::posix_time::ptime(static_cast<const boost::gregorian::date>(alarm_date), alarm_time);
}

void TimerAlarm::setAlarm() {
    int minutes;
    int seconds;
    int hour;
    std::cout << "Enter the alarm hour: "sv;
    std::cin >> hour;
    std::cout << "Enter the alarm minutes: "sv;
    std::cin >> minutes;
    std::cout << "Enter the alarm seconds: "sv;
    std::cin >> seconds;

    boost::posix_time::time_duration alarm_time = boost::posix_time::hours(hour) +
                                                  boost::posix_time::minutes(minutes) +
                                                  boost::posix_time::seconds(seconds);

    boost::posix_time::ptime alarm_date_time = calculateAlarmDateTime(alarm_time);

    std::cout << "The alarm will go off at "sv << alarm_date_time << std::endl;

    // Start a separate thread to check the alarm
    std::future<void> alarm_future = std::async(std::launch::async, &TimerAlarm::checkAlarm, this, alarm_date_time);
    alarm_future.wait(); // Wait for the alarm thread to finish
}

void TimerAlarm::start() {
    char choice = getValidChoice();

    if (choice == 'T') {
        setTimer();
    } else if (choice == 'A') {
        setAlarm();
    }
}

int main() {
    TimerAlarm timerAlarm;
    timerAlarm.start();

    return 0;
}
