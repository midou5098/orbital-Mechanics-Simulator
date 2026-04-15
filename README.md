# 🪐 Orbital System Visualizer (SDL2 + C++)

> Interactive space simulation and UI-driven orbital visualizer built with C++ and SDL2.

---

## 🚀 Overview

This project is an interactive graphical application built in C++ using SDL2 that simulates orbital motion and provides a simple UI system for managing and visualizing celestial objects.

It combines:

* a lightweight rendering wrapper
* a UI framework
* animated sprite rendering
* and a 2D orbital simulation system

The project is structured as a small custom engine-like architecture rather than a single-purpose script.

---

## ✨ Features

* 🪐 Real-time orbital simulation of multiple planets
* 🌍 Planet system with customizable properties
* 🎮 Interactive UI for adding celestial bodies
* ✍️ Text input system for planet attributes
* 🌗 Scene switching (UI ↔ space view)
* 🎞️ Sprite-based animation system
* 🌌 Background space rendering
* 🔄 Smooth transition effects (fade in/out)
* 📐 Circular orbit rendering using SDL2_gfx

---

## 🛠️ Tech Stack

* **Language:** C++
* **Graphics:** SDL2
* **Add-ons:**

  * SDL2_ttf (text rendering)
  * SDL2_image (texture loading)
  * SDL2_gfx (orbit rendering primitives)
* **Core Concepts:**

  * Object-oriented design
  * Game-loop architecture
  * State machines (scene switching)
  * Sprite animation systems
  * Trigonometric motion simulation

---

## 🧠 Architecture Overview

The project is split into three main components:

### 1. `SDLinit`

A lightweight SDL wrapper handling:

* Window creation
* Renderer lifecycle
* Text rendering
* UI primitives (buttons, text areas)

### 2. `uinter` (UI + Engine Layer)

Handles:

* Scene management (mode switching)
* Input processing (mouse + keyboard)
* Planet creation system
* Animation control
* Rendering logic per scene

### 3. `planet` Model

Represents celestial bodies with:

* ID-based classification
* Name/species metadata
* Size and population attributes
* Orbital angle state

---

## 🌍 Simulation Logic

Each planet follows a circular orbit:

* Position computed using:

  * `x = centerX + cos(angle) * radius`
  * `y = centerY + sin(angle) * radius`

* Each frame:

  * angle is incremented
  * sprite is rendered at updated position

This creates smooth orbital motion around a central “sun”.

---

## 🎮 Controls

### UI Mode (Planet Creation)

* Click input fields to type:

  * Planet name
  * Orbital distance
  * Species
* Select planet type (Earth / Venus / Mars / Saturn)
* Click **Deploy** to add planet to simulation

### Space Mode (Simulation)

* `ESC` → return to UI / toggle scene
* Planets automatically orbit the sun in real time

---

## 🎨 Visual System

* 🟡 Sun rendered at center
* 🔵 Planets rendered as animated sprites
* ⚪ Orbits rendered using SDL2_gfx circles
* 🌌 Background space texture
* 🌫️ Fade transition overlay between scenes

---

## 📁 Project Structure

```
project/
├── main.cpp            # Application entry point (game loop)
├── headers.h           # SDL wrapper + UI system + engine logic
├── assets/
│   ├── space.png
│   ├── earth.png
│   ├── venus.png
│   ├── mars.png
│   ├── saturn.png
│   ├── sun.png
├── font.ttf
├── README.md
```

---

## ⚙️ Build Instructions

### Linux

```bash
g++ main.cpp -o orbital -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_gfx
```

### Run

```bash
./orbital
```

---

## 📸 Demo

*Add GIF or screenshots of orbital motion + UI screen*

---

## 🎯 Purpose

i ve been always interested in space and planets , and since the concept of c++ classes
and constructers/destructers is still a new thing , i built this project to get more comfortable abt it , 
while learning more abt newton laws and how planets orbit.

---

## 🧠 What I Learned

tbh nothing new , i just got wayyyy more comfortable with classes , sdl and crud rythme , wanted to implement more calculations for the planet ,
but it wouuld require more details and inputs so i just simplified it for now

---

## 🚧 Status

* UI system: ✅
* Planet creation system: ✅
* Orbital simulation: ✅
* Animation system: ✅
* Scene transitions: ✅
* Extended features: ⏳ may come back later to expand the planets details input.

---



## ⚠️ Notes

* This project is structured like a lightweight engine rather than a simple program
* Orbital motion is purely mathematical (not physics-based gravity simulation)
* SDL2_gfx is used for efficient orbit rendering

---

## 🤝 Contributing

Contributions are welcome. Feel free to open issues or submit pull requests.

---

## 📄 License

*no licence gng
