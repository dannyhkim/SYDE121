// *********************************************************************************************************************
//
// Student Name: Daniel Kim
// Student Number: 20784291
// SYDE 121 Lab: WEEF Lab
// Assignment Number: 2
// Filename: lab03_03.cpp
// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

// Project: Horoscope Sign
// Purpose: Finds the user's horoscope sign and astrological element.
// Due Date: Friday, September 28, 2018

/*
 To test the program logic, I first started with inputting various invalid values at different stages of the user input
 process to see if the program would respond correctly. The first step was to input values like 0, 14, and -5 for month
 values. The program would ask the user to re-enter a proper value.
 After, I checked whether the days were restricted based on their months. For February, I inputted 30 to see if the
 program would respond by saying it is an invalid input. For months like April and June where there are only 30 days,
 I inputted 31 to see if it was invalid. For months with 31 days, I inputted day values of 32 to see if it was invalid.

 After testing the part of the code in charge of identifying invalid inputs, I checked various values for each horoscope
 sign to see if they inputted the correct info corresponding to each date. Since the signs are not categorized by month,
 but rather one half of two different months, I inputted a value corresponding to the first month that the horoscope
 sign is related to, and then a value belonging to the 2nd month of the horoscope sign.
 For example, Aquarius' are born between January 20 - February 18. To check if the correct info was being outputted,
 I inputted January 20, and February 15 to see if Aquarius' info was outputted for both. As well, I also inputted values
 in which the signs were changing, such as 03 21, and 04 20 to see if the restrictions were done correctly.
 */

#include <iostream>
using namespace std;

int main() {

    //Variable declaration
    int month, dob;

    //Asks user for month they were born in, assigns value to "month" variable.
    cout << "Enter the month you were born in number format MM." << endl;
    cin >> month;

    //Does not allow user to proceed unless proper month is entered.
    while (month < 1 || month > 12){
        cout << "Invalid month number. Please try again." << endl;
        cin >> month;
    }

    //Asks user to enter day of birth and assigns it to variable "dob"
    cout << "Enter the day you were born on in number format DD." << endl;
    cin >> dob;

    //if the month has 31 days, allows user to enter a day between 1 and 31
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        //asks user to re-enter a valid day
        while (dob < 1 || dob > 31){
            cout << "Invalid day of birth. Please try again." << endl;
            cin >> dob;
        }
    //if the month has only 30 days, the user can only enter a number between 1 and 30
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
        while (dob < 1 || dob > 30){
            cout << "Invalid day of birth. Please try again." << endl;
            cin >> dob;
        }
    //if the month they entered was February (2), they can only enter a number between 1 and 29 for the day
    } else {
        while (dob < 1 || dob > 29){
            cout << "Invalid day of birth. Please try again." << endl;
            cin >> dob;
        }
    }

    //block of if statements deciding what horoscope sign, information, astrological element, and compatible horoscope
    //sign to output

    //Aquarius

    //Conditions for if user is born in either part of the two months
    if ((month == 1 && dob > 19 && dob < 32) || (month == 2 && dob > 0 && dob < 19)){
        cout << "Horoscope sign: Aquarius" << endl;
        cout << "You are aware of your capacities and won’t take any more work than you are truly able to handle.\n"
                "Believe in your organizational abilities this time around, leaving little room for others to doubt\n"
                "you along the way. You can do whatever seems right when you move with the tides and believe in yourself."
                << endl;

        cout << "\nAstrological element: Air\nAir signs are rational, social, and love communication and relationships\n"
                "with other people. They are thinkers, friendly, intellectual, communicative and analytical. They love\n"
                "philosophical discussions, social gatherings and good books." << endl;
        cout << "\nCompatible horoscope signs: Leo, Sagittarius" << endl;

    //Pisces
    } else if((month == 2 && dob > 18 && dob < 30) || (month == 3 && dob > 0 && dob <21)){
        cout << "Horoscope sign: Pisces" << endl;
        cout << "Pisces are very friendly, so they often find themselves in a company of very different people.\n"
                "Pisces are selfless, they are always willing to help others, without hoping to get anything back.\n"
                "Pisces is a Water sign and as such this zodiac sign is characterized by empathy and expressed emotional\n"
                "capacity." << endl;

        cout << "\nAstrological element: Water\nWater signs are exceptionally emotional and ultra-sensitive. They are\n"
                "highly intuitive and they can be as mysterious as the ocean itself. Water signs love profound\n"
                "conversations and intimacy." << endl;
        cout << "\nCompatible horoscope signs: Virgo, Taurus" << endl;

    //Aries
    } else if ((month == 3 && dob > 20 && dob < 31) || (month == 4 && dob > 0 && dob < 20)){
        cout << "Horoscope sign: Aries" << endl;
        cout << "Aries is courageous, determined, confident, optimistic, but also impatient, moody, short-tempered,\n"
                "and impulsive. Aries rules the head and leads with the head, often literally walking head first, \n"
                "leaning forwards for speed and focus." << endl;

        cout << "\nAstrological element: Fire\nFire signs tend to be passionate, dynamic, and temperamental.\n"
                "They get angry quickly, but they also forgive easily. They are adventurers with immense energy.\n"
                "They are physically very strong and are a source of inspiration for others." << endl;
        cout << "\nCompatible horoscope signs: Libra, Leo" << endl;

    //Taurus
    } else if((month == 4 && dob > 19 && dob < 31) || (month == 5 && dob > 0 && dob < 21)){
        cout << "Horoscope sign: Taurus" << endl;
        cout << "Practical and well-grounded, Taurus is the sign that harvests the fruits of labor. They feel the need\n"
                "to always be surrounded by love and beauty, turned to the material world, hedonism, and physical\n"
                "pleasures. People born with their Sun in Taurus are sensual and tactile, considering touch and taste\n"
                "the most important of all senses." << endl;

        cout << "\nAstrological element: Earth\nEarth signs are “grounded” and the ones that bring us down to earth.\n"
                "They are mostly conservative and realistic, but they can also be very emotional. They are connected\n"
                "to our material reality and can be turned to material goods." << endl;
        cout << "\nCompatible horoscope signs: Scorpio, Cancer" << endl;

    //Gemini
    } else if((month == 5 && dob > 20 && dob < 32) || (month == 6 && dob > 0 && dob < 21)){
        cout << "Horoscope sign: Gemini" << endl;
        cout << "Expressive and quick-witted, Gemini represents two different personalities in one and you will never\n"
                "be sure which one you will face. They are sociable, communicative and ready for fun, with a tendency\n"
                "to suddenly get serious, thoughtful and restless." << endl;

        cout << "\nAstrological element: Air\nAir signs are rational, social, and love communication and relationships\n"
                "with other people. They are thinkers, friendly, intellectual, communicative and analytical. They love\n"
                "philosophical discussions, social gatherings and good books." << endl;
        cout << "\nCompatible horoscope signs: Sagittarius, Aquarius" << endl;

    //Cancer
    } else if((month == 6 && dob > 20 && dob < 31) || (month == 7 && dob > 0 && dob < 23)){
        cout << "Horoscope sign: Cancer" << endl;
        cout << "Deeply intuitive and sentimental, Cancer can be one of the most challenging zodiac signs to get to know.\n"
                "They are very emotional and sensitive, and care deeply about matters of the family and their home.\n"
                "Cancer is sympathetic and attached to people they keep close." << endl;

        cout << "\nAstrological element: Water\nWater signs are exceptionally emotional and ultra-sensitive. They are\n"
                "highly intuitive and they can be as mysterious as the ocean itself. Water signs love profound\n"
                "conversations and intimacy." << endl;
        cout << "\nCompatible horoscope signs: Capricorn, Taurus" << endl;

    //Leo
    } else if((month == 7 && dob > 22 && dob < 32) || (month == 8 && dob > 0 && dob < 23)){
        cout << "Horoscope sign: Leo" << endl;
        cout << "People born under the sign of Leo are natural born leaders. They are dramatic, creative, self-confident,\n"
                "dominant and extremely difficult to resist, able to achieve anything they want to in any area of life\n"
                "they commit to. There is a specific strength to a Leo and their \"king of the jungle\" status.\n"
                "Leo often has many friends for they are generous and loyal." << endl;

        cout << "\nAstrological element: Fire\nFire signs tend to be passionate, dynamic, and temperamental.\n"
                "They get angry quickly, but they also forgive easily. They are adventurers with immense energy.\n"
                "They are physically very strong and are a source of inspiration for others." << endl;
        cout << "\nCompatible horoscope signs: Aquarius, Gemini" << endl;

    //Virgo
    } else if((month == 8 && dob > 22 && dob < 32) || (month == 9 && dob > 0 && dob < 23)){
        cout << "Horoscope sign: Virgo" << endl;
        cout << "Virgos are always paying attention to the smallest details and their deep sense of humanity makes them\n"
                "one of the most careful signs of the zodiac. Their methodical approach to life ensures that nothing is\n"
                "left to chance, and although they are often tender, their heart might be closed for the outer world." << endl;

        cout << "\nAstrological element: Earth\nEarth signs are “grounded” and the ones that bring us down to earth.\n"
                "They are mostly conservative and realistic, but they can also be very emotional. They are connected\n"
                "to our material reality and can be turned to material goods." << endl;
        cout << "\nCompatible horoscope signs: Pisces, Cancer" << endl;

    //Libra
    } else if((month == 9 && dob > 22 && dob < 31) || (month == 10 && dob > 0 && dob < 23)){
        cout << "Horoscope sign: Libra" << endl;
        cout << "People born under the sign of Libra are peaceful, fair, and they hate being alone. Partnership is very\n"
                "important for them, as their mirror and someone giving them the ability to be the mirror themselves.\n"
                "These individuals are fascinated by balance and symmetry, they are in a constant chase for justice and\n"
                "equality, realizing through life that the only thing that should be truly important to themselves in\n"
                "their own inner core of personality." << endl;

        cout << "\nAstrological element: Air\nAir signs are rational, social, and love communication and relationships\n"
                "with other people. They are thinkers, friendly, intellectual, communicative and analytical. They love\n"
                "philosophical discussions, social gatherings and good books." << endl;
        cout << "\nCompatible horoscope signs: Aries, Sagittarius" << endl;

    //Scorpio
    } else if((month == 10 && dob > 22 && dob < 32) || (month == 11 && dob > 0 && dob < 22)){
        cout << "Horoscope sign: Scorpio" << endl;
        cout << "Scorpio-born are passionate and assertive people. They are determined and decisive, and will research\n"
                "until they find out the truth. Scorpio is a great leader, always aware of the situation and also\n"
                "features prominently in resourcefulness." << endl;

        cout << "\nAstrological element: Water\nWater signs are exceptionally emotional and ultra-sensitive. They are\n"
                "highly intuitive and they can be as mysterious as the ocean itself. Water signs love profound\n"
                "conversations and intimacy." << endl;
        cout << "\nCompatible horoscope signs: Taurus, Cancer" << endl;

    //Sagittarius
    } else if((month == 11 && dob > 21 && dob < 31) || (month == 12 && dob > 0 && dob < 22)){
        cout << "Horoscope sign: Sagittarius" << endl;
        cout << "Curious and energetic, Sagittarius is one of the biggest travelers among all zodiac signs. Their open\n"
                "mind and philosophical view motivates them to wander around the world in search of the meaning of life.\n"
                "Sagittarius is extrovert, optimistic and enthusiastic, and likes changes." << endl;

        cout << "\nAstrological element: Fire\nFire signs tend to be passionate, dynamic, and temperamental.\n"
                "They get angry quickly, but they also forgive easily. They are adventurers with immense energy.\n"
                "They are physically very strong and are a source of inspiration for others." << endl;
        cout << "\nCompatible horoscope signs: Gemini, Aries" << endl;

    //Capricorn
    } else if((month == 12 && dob > 21 && dob < 32) || (month == 1 && dob > 0 && dob < 20)){
        cout << "Horoscope sign: Capricorn" << endl;
        cout << "Capricorn is a sign that represents time and responsibility, and its representatives are traditional\n"
                "and often very serious by nature. These individuals possess an inner state of independence that enables\n"
                "significant progress both in their personal and professional lives." << endl;

        cout << "\nAstrological element: Earth\nEarth signs are “grounded” and the ones that bring us down to earth.\n"
                "They are mostly conservative and realistic, but they can also be very emotional. They are connected\n"
                "to our material reality and can be turned to material goods." << endl;
        cout << "\nCompatible horoscope signs: Taurus, Cancer" << endl;
    }
    //program terminates
    return 0;
}