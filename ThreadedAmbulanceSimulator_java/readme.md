# 1. Concurrent programming assignment

## Assignment
Goal of the assignment was to make simulation of ambulance service which had three components. Ambulances, incidents and hospital. By using the *Producer Consumer Barber* example

 - Incidents are generated at random positions with *maxLocX* and *maxLocY* parameters
 - Hospital is generated at random position with *hospitalX* and *hospitalY* parameters
 - Ambulances generated with *speed* and *count* parameters.

When incident is generated idle ambulance will move to its location at the time of (t) which is calculated with distance (d) and given speed (v)

$t = d/v$

After that we calculate average speed amount (v) with  time that elapsed during the hospital -> incident site trip with incident site -> hospital distance (d) 

$v = d/t$

After that we use the $t = d/v$ again to calculate the travel time from incident site -> hospital.

Once we are at the hospital it takes 10 seconds to transfer patient to hospital. After that said ambulance will be free to perform other duties.

I really didn't understand what the 20 iterations part about the assignment was all about. How many incidents there has to be in a one loop and for how long one iteration has to run?

## Solution

At first I implemented all the corresponding classes such as Ambulance, Incident and Hospital.
Then I implented the existing producer-, consumer -patterns and CircularBuffer.

Ambulance class uses the *Consumer* pattern and IncidentGenerator uses the *Producer* pattern.

### `Main.java`

Creates objects needed for the program.

Everytime location of hospital is randomized within a sensible range and max Size of the grid is also randomized.

At launch it asks how many ambulances we want to have and then that many ambulances are created with (buffer, ambulanceNum, randomSpeed, hospital) arguments.

Every ambulance gets the one and only hospital object as an argument, so that every object knows where said hospital is located.

Ambulance objects are stored in a list and in a separate for loop that list is looped trough so we can create n amount of ambulance threads and then start them.

### `Ambulance.java`

``protected void consume(Object obj)``

Is the main method where things happen. Basically when new incident is created some available ambulance starts to travel towards it.
Illusion of traveled distance is made with ``Thread.sleep()``. Sleep time is calculated with the expression given above.

After that programs prints out that the ambulance is on site, and them amount of time that elapsed during the trip.

Then ambulance starts to move towards hospital and Thread.Sleep() time is used the same way as before.

Then sleep for 10seconds when patient is getting transferred to hospital. Program notifies when patient has been transferred with total duration in milliseconds.

### `IncidentGenerator.java`

Pretty much same thing as in Sleeping Barber problem but each Incident object gets randomized locations when created.

