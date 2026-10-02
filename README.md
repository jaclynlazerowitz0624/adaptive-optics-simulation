# Adaptive Optics Simulation: Ortho-K Rebound & Liquid Crystal Accommodation

A C++ and SFML simulation modeling corneal rebound decay post-Ortho-K lens removal and testing conceptual liquid crystal phase adjustments for real-time optical correction.

---

## 👁️ Motivation & Scope

I built this simulation to explore how adaptive optics can address expected and unprecedented vision shifts. Having worn Ortho-K lenses for half my life, I experienced firsthand the unpredictable daily vision shifts caused by corneal rebound—and the complete lack of tools to track or get used to those changes between doctor visits. I created this simulation as a first step toward modeling how liquid crystal optical paths and continuous corneal decay monitoring could work together to bridge that gap.

* **User Inputs:**  
  _Corneal Decay Settings/Parameters_: Baseline vision values and rates for how fast the cornea relaxes back over time.
  _Live Controls_: Interactive toggles to tweak light path variations and test how the simulation handles environmental noise as you run it.
* **Simulation Outputs:**  
  _Visual Wavefront View_: A real-time 2D SFML display showing light phase shifts moving across the simulated liquid crystal array.
 _Console Diagnostics_: Live terminal update tracking focal error, phase delays, and frame rate performance.

> **A Note on Engineering Scope:**
> This is strictly a software simulation built to test math models and foster curiosity. Building physical liquid crystal adaptive lenses requires complex hardware integration, wavefront sensors, and bio-material testing that is far more intricate and faceted than this project. This project serves as my personal sandbox to explore optical physics and challenge my C++ skills.

---

## 🛠️ Build & Setup

* **Language:** C++17 (Self-taught over 6+ months using SoloLearn, technical documentation, and tutorials)
* **Graphics:** SFML (Simple and Fast Multimedia Library)
* **Environment:** Native Linux environment on ChromeOS

```bash
# Compile
g++ main.cpp -o optics_sim -lsfml-graphics -lsfml-window -lsfml-system

# Run
./optics_sim
```
---

## 📚 Applied Mathematics & Core Engineering

The simulation transforms physical wave interactions into discrete numerical calculations evaluated frame-by-frame within the C++ main loop:

* **Snell’s Law & Refraction:**
Calculates how light bends and changes speed when moving through different optical materials using `n1 * sin(θ1) = n2 * sin(θ2)`.

* **Wave Phase Shift & Interference:**
Models how light waves travel across the lens. Differences in the light path create bright and dark interference patterns on the sensor.

* **Exponential Corneal Rebound Decay:**
Uses an exponential decay equation, `R(t) = R0 * e^(-λt)`, to simulate how the cornea gradually relaxes back to its natural shape over time after removing Ortho-K lenses.

* **Spatial Gradients & Gaussian Noise:**
Measures how fast light patterns change or shift across the grid while adding realistic sensor noise to simulate real-world conditions.
---

## 🚀 Relevant Coursework & Engineering Horizons

### Class-to-Code Mapping
* **AP Physics 2 & Honors Physics 1:** Used core physics concepts like Snell's law, wave behavior, and light bending and refraction to build the light distortion model.
* **AP Calculus AB:** Used rates of change and exponential decay formulas to simulate how the cornea returns to its shape over time.
* **AP Statistics:** Used probability distribution concepts to add realistic noise to the sensor array.
* **AP Computer Science A & Independent Java/C++:** Turned math equations into clean C++ code and managed how data updates on screen in every frame.
* **Regents Chemistry & Biology:** Used ideas from biology and tissue behavior to make sure the corneal relaxation model makes sense physically.

### Alignment with Electrical & Computer Engineering
* **Signal Processing & Systems:** Working with light wave delays in code is directly related to processing signals and filtering out clutter in digital systems.
* **Multivariable Calculus (Some Concepts Learned Independently) & Advanced Math:** Calculating changes across a 2D grid builds a foundation for multivariable calculus, linear algebra, and 3D modeling.

### Future Scope & Explorations
* **Active Sensor Loops:** Adding a system that automatically detects visual blur and corrects it in real time.
* **Better Visual Detail:** Improving render resolution to make light waves look smoother on screen.
* **Real-Time Correction Algorithms:** Writing code that calculates exact inverse phase delays to flatten out light distortion automatically.
