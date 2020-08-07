Tools: Visual Studio 2017

Language: C++

I used a library of Vector3D which was created by myself.

This program simulates the radar workflow: detect positions of objects, print the positions on the screen, clear the objects.

I suppose The target is always at (0,0,0) and consider car or person is a point.
I used random position to simulate the position of car or person.
I think the test is focus on direction of object so i don't pay attention on the volume of a car. If we consider the volume, then just add a circle collider at the center of car and calculate the min distance between the collider and the target.


How to use test the programme:
press g will create an array of objects randomly
press p will print the positions of objects in an array

To calculate the angle between target and object i used dot product of 2 vectors = |a||b| cos(angle)
To check if target's vector is in front of or behind of (1,0,0), i used crossProduct.

PS: There is a cross product issue in my library of Vector3D. (fixed)

Advanced : we can use BSP or octree to divide the space...