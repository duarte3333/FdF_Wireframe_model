
# Creating a Wireframe model
<p align="center">
	<a href="https://www.youtube.com/watch?v=YX3Kaq3ehL4&ab_channel=DuarteMorais"</a><img class="center" src="https://user-images.githubusercontent.com/76222459/210257207-1f52b93c-ed83-4b5a-bad9-cd5f2400a37d.png" width=70% height=70%>
</p>
<p align="center">
<b>Click on the image to see the video (Put in 1080p !)</b>
</p>

## Introduction
Wireframe models are an essential tool in the world 
of graphics programming, as they allow designers and 
developers to visualize and understand the structure 
and layout of 3D objects without the need for surface 
details or textures. In this project, my main goal was
to create a simple wireframe model representation of 
a 3D landscape by linking various points (x, y, z) 
using line segments (edges).

To create the wireframe model, I used a combination 
of graphics programming techniques and spatial geometry 
principles. By linking points in 3D space using line segments,
I was able to represent the basic structure and layout of the 
landscape. This process allows to visualize and understand 
the overall shape and form of the landscape, as well as identify 
any potential issues or areas for improvement.

One of the key advantages of using a wireframe model in this 
context is the ability to quickly and easily manipulate and 
modify the model as needed. By adjusting the position of points 
and line segments, I was able to refine the overall structure 
and layout of the landscape to better match our desired design.


## Theory
### Isometric projection
To convert 3D coordinates into 2D isometric projection coordinates I used the following formula:

```c
    x = (isoX - isoY) * cos(30)
    y = (isoX + isoY) * sin(30) - isoZ
```
where isoX and isoY are the isometric projection's x and y coordinates, and isoZ is the isometric projection's z coordinate.

### Parallel projection
To convert 3D coordinates into 2D parallel projection coordinates I used the following formula:
```c
    x = (parellX - parellZ) * cos(45)
    y = (pparellY - parellZ) * sin(45)
```
where parellX and parellY are the parallel projection's x and y coordinates, and parellZ is the paralell projection's z coordinate.
### Rotation Matrix
A rotation matrix is a matrix that is used to rotate a point or a vector in a coordinate system.
#### X-Axis Rotation
![image](https://user-images.githubusercontent.com/76222459/210239625-eded2eed-5b94-4e6d-b626-4f693641afb0.png)

After the transformations, we will get the formulas:

![image](https://user-images.githubusercontent.com/76222459/210239284-77618824-e3e1-4420-ba36-3698c4d7e279.png)

#### Y-Axis Rotation

![image](https://user-images.githubusercontent.com/76222459/210239645-828612ad-35ec-4043-93c1-68a9a2bf77ea.png)

After the transformations, we will get the formulas:

![image](https://user-images.githubusercontent.com/76222459/210239336-3b2eeea8-3585-421f-a292-09cea99418e1.png)

#### Z-Axis Rotation

![image](https://user-images.githubusercontent.com/76222459/210239674-f314ed8e-97ce-463b-bf79-50d031d404a9.png)

After the transformations, we will get the formulas:

![image](https://user-images.githubusercontent.com/76222459/210239369-2ab8a3c3-1383-428f-ac04-2c3208df1680.png)

See my rotations working in this video: [Rotations](https://user-images.githubusercontent.com/76222459/210237839-fba32f2a-cbd6-4070-ba7a-b709025a78f0.webm)

## To draw a line
The most common algorithms that can be used to draw lines in a pixel window include:

#### Bresenham's line algorithm: 
This algorithm uses integer arithmetic and decision variables to draw a line between two points with minimal computation. It is simple to implement and efficient, but it can only draw lines with a slope between -1 and 1.

#### DDA (Digital Differential Analyzer) algorithm: 
This algorithm uses floating-point arithmetic to draw a line between two points by incrementally increasing the x or y coordinate by the slope of the line. It is simple to implement but relatively slow compared to other algorithms.

#### Xiaolin Wu's line algorithm:
This algorithm uses anti-aliasing to smooth the edges of the line and produce a higher quality image. It is more complex to implement than Bresenham's algorithm but produces better results.

#### Cohen-Sutherland line clipping algorithm:
This algorithm is used to clip a line to a specific region, such as a window or viewport. It uses a four-bit code to represent the position of a point relative to the clipping region, and uses logical operations to determine which parts of the line are inside or outside the region.

#### Liang-Barsky line clipping algorithm:
This algorithm is similar to the Cohen-Sutherland algorithm, but it uses parameterized equations to represent the line and uses interval arithmetic to determine which parts of the line are inside or outside the clipping region. It is generally faster than the Cohen-Sutherland algorithm.

#### My choice
The major problem of this project is to draw all the lines. For this I start with the Bresenham's line 
algorithm but then I switch to the [Linear interpolation](https://en.wikipedia.org/wiki/Linear_interpolation) 
approach because it was simpler for a first implementation.
Then, I realize that the linear interpolation is not very efficient, because in the 
situation of any two points are to far away of each other the line doesnt seem drawn.
For that reason, I switch to a variation of the [Digital Differential Analyzer (DDA) algorithm](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)). 
The algorithm is called the Digital Difference Analyzer because it interpolates points based on 
the difference between the start and end points. 
So after a few implementations I ended up using the [Digital Differential Analyzer algorithm](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)):
![image](https://user-images.githubusercontent.com/76222459/210245840-fb3c0316-2b2c-45f8-99cd-a5179cc9458e.png)

## Color gradient
Another challenge was creating a color gradient that change depending on 
the height of the projection. 

To do this, at each line drawn, I defined the difference between 
the maximum and minimum height of the begin and end points with the variable 
vars->range_z. At first the vars-rgb_p represents the percentage of the first point of the line in the scale 
where at z_min is zero and at z_max is one.
```c
    vars->rgb_p = a.z / vars->new_max;
	if (b.z - a.z > 0)
		vars->range_z = (b.z / vars->new_max - vars->rgb_p);
	else
		vars->range_z = -(a.z / vars->new_max - b.z / vars->new_max);
```
So then at each x I drew, I calculated the color percent for each point:
```c
while (b.x - x != 0)
{
	color_percent = color_percent + range_z / pixels_per_drawing;
    my_mlx_pixel_put(vars, x, y, percent_to_color(vars->rgb_p, vars->flag));

}
```
After knowing what percentage of the scale each z was in the scale, I called a function in the 
color.c file that based on that percentage choose the color of the point.

Check out a video of the gradient colors that I created: [Colors](https://user-images.githubusercontent.com/76222459/210249785-361b50f2-f969-4aa6-878b-f93eeea3a4dd.webm)
## Results


<img src="https://user-images.githubusercontent.com/76222459/210259689-454fa6e6-0368-4380-8e8d-c13eaabcdb7a.jpg" width=120% height=120%>


<img src="https://user-images.githubusercontent.com/76222459/210260366-b766a492-7a79-498c-9961-603c6c137e82.jpg" width=100% height=120%>

![combine_images (22)](https://user-images.githubusercontent.com/76222459/210262922-7c640a93-7912-4afe-8b1c-688d61baa5b2.jpg)

## Possible Views
![combine_images (21)](https://user-images.githubusercontent.com/76222459/210261931-f13bbba1-d4bd-41c6-ac27-bf9a4de3b56a.jpg)
The possible views of the program, in the upper left corner we have the front view, below we have the top view. In the center 
we have the right side view and below the isometric view. Additionally in the lower right corner it is possible to see the parallel view.


## Flowchart
![flow_final drawio](https://user-images.githubusercontent.com/76222459/210188894-10131e6d-98a2-4aa4-a6c9-2c1d5d0d79a5.png)

## Menu 

In order to change things in the program during is execution, the screen shows the following menu:

![image](https://user-images.githubusercontent.com/76222459/210263201-d0640c2d-ea28-4a24-8258-d87fa94c301b.png)

## Applications of wireframe models

1. Computer-aided design (CAD): Wireframe models are often used in CAD 
software to represent the basic structure and layout of objects and systems. 
infrastructure to automobiles and aircraft.

2. Computer graphics: Wireframe models are commonly used in computer 
graphics to represent 3D objects in games and other interactive media. 
They are often used as a starting point for more complex models with 
surface details and textures.

3. Architecture: Architects and urban planners often use wireframe models to 
visualize and understand the structure and layout of buildings and cities.

4. Industrial design: Industrial designers use  wireframe models to represent 
the basic structure and layout of products such as furniture, appliances, and consumer electronics.

5. Film and animation: Wireframe models are used in the film and animation 
industry to represent 3D objects and environments in pre-visualization and 
planning stages.

6. Virtual reality: Wireframe models are often used to create immersive 
virtual reality experiences, as they provide a basic structure and layout 
for the virtual environment without the need for high levels of detail.

### Minilibx

The **minilibx** is a small C library used for rendering graphics, primarily used by [42](https://en.wikipedia.org/wiki/42_(school)) students. Is built on top of the X Window System API, to provide a much simpler programming interface suited for beginners. Indeed, no X knowledge is needed at all to render graphics properly using this kind of library.

In order to understand the library I used here is the documentation: [42 Minilibx Docs](https://harm-smits.github.io/42docs/libs/minilibx)
### Xlib

The X Window System is a network-transparent window system that was designed at MIT. X display servers run on computers with either monochrome or color bitmap display hardware. The server distributes user input to and accepts output requests from various client programs located either on the same machine or elsewhere in the network. Xlib is a C subroutine library that application programs (clients) use to interface with the window system by means of a stream connection. Although a client usually runs on the same machine as the X server it is talking to, this need not be the case.

[Getting start with Minilibx](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)
