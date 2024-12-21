This simulation is created purely in C++ and SFML for rendering. No physics or game engine were used.

Each termites are flying around following and algorithm with two simple rules:

1. Stay flying around an active source of light within a specific radius (r) from the light source.
2. If is not within the radius (r) from an active source of light, fly towards the closest light 'visible'*.

*Visible meaning the the path between the termite's position and the light source is not blocked by a wall.

Classes: Game, Termite, Lamp, Light, Wall, Utils.

[Game]
This is where the game loops happen and where the game elements are initialized.
Functions inlcude processEvents(), update(), and render().

[Termite]
This class has the constructor for the termites, with behave() and render() as the main functions.
behave() is called every frame in Game::update(), it alters the position of the termite with algorithms for:

- Getting the positions of active lights, and sort based on the distance.
- Checking each light, starting from the closest, if there is a wall between it and the termite's position.
- Avoiding collision with the wall using Set Axis Theorem projections. - Fly towards a light source, or stay within the current light zone, or fly around current position according to results of the previous algorithms.

<img class="mobileWid" src="/assets/wallbetween.png" alt="wallbetween diagram">
The isWallBetween() function compares the angles of the path to the light and to each corner with the largest angle between two corner points of the wall, all in respect to the termite position.

[Lamp]
A simple class that holds the constructor for lamps and a render() function.
Inside the render() function, there is a conditional color setting based on wether or not the corresponding light is Active. It renders as yellow when active, and grey otherwise.

[Light]
The Light class contains the light constructor and basic functions to set its booelan state, isActive. Each light should be paired with a lamp.

[Wall] The Wall is constructed by taking two vertices to form the longer side of a rectangle
The render() function generates two more vertices that are offset from first two by a value as the width of the wall.
The four vertices are then connected to form a rectangle using SFML's Drawable Vertex. The vertices are then used for SAT collision detection.

[Utils] The utils class contains useful calculation functions to be called by other classes, such as dotProduct(), getLength() and a Projection struct containing min and max float values to be compared in SAT collision detection.
