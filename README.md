# OGL Gen Reflect File Application

this is an application for generating the static reflection file for the 
OGL (Oniup's Graphics Library) reflection system. The App will Generate a 
Shared or static library file with all struct/classes that has a 
OGL_SERIALIZABLE_OBJECT() macro. However if OGE (Oniup's Game Engine), then 
this application should be automatically called after every time you make 
changes to your project.

links: 

* [OGL](https://github.com/Oniup/ogl.git)
* [OGE (Oniup's Game Engine)](https://github.com/Oniup/oge.git)

## Example Code

the following code declares whether it needs to be a serializable object

```cpp
struct Player {
    OGL_SERIALIZABLE_OBJECT()

    int health{ 10 };
    float move_speed{ 20.0f };
    ogl::ColliderComponent* component{ nullptr };
};
```

if a member is not needed to be serialized or ot be avoided completely by the reflection
system, can use the following macros:

* OGL_NO_SERIALIZE
* OGL_NO_REFLECT

```cpp
struct Player {
    OGL_SERIALIZABLE_OBJECT()

    int health{ 10 };
    float move_speed{ 20.0f };

    OGL_NO_SERIALIZE()
    ogl::ColliderComponent* component{ nullptr };

    OGL_NO_REFLECT()
    glm::vec3 move_direction{};
};
```

## Console Application Use

The application has multiple commands and is defined by adding a ``` - ``` before 
all the file locations. Node that you can add multiple commands:

### -d

enables debug output to the console

### -s

reads the defined files and generates the reflection files

```bash
ogl_gen_reflection_file -s __SOURCE_FILES__ -r __GEN_REFLECTION_DEST__
```

### -c

Generates cmake file for compiling the executable. Must defined whether it is 
a shared or static library by following the command with either d (shared) or s 
(static). Note that if -g has already been used, there is no need to define the 
```__REFLECTION_DESTINATION_FILE__```

```bash
ogl_gen_reflection_file -cd __GEN_CMAKE_FILE_DEST__
```

example of using all the commands:

```bash
ogl_gen_reflection_file 
-d 
-s ../role_ball_game/src/player.hpp role_ball_game/src/enemy.hpp 
-r../role_ball_game/reflection_definitions
-cs ../role_ball_game/reflection_definitions
```
