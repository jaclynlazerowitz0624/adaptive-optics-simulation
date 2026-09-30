# Adaptive Optics Simulation: Ortho-K Rebound & Liquid Crystal Accommodation

A C++ and SFML simulation modeling corneal rebound decay post-Ortho-K lens removal and testing conceptual liquid crystal phase adjustments for real-time optical correction.

---

## 👁️ Motivation & Scope

I built this simulation to explore how adaptive optics can address expected and unprecedented vision shifts. Having worn Ortho-K lenses for half my life, I experienced firsthand the unpredictable daily vision shifts caused by corneal rebound—and the complete lack of tools to track or get used to those changes between doctor visits. I created this simulation as a first step toward modeling how liquid crystal optical paths and continuous corneal decay monitoring could work together to bridge that gap.

* **User Inputs:**  
  _Corneal Decay Parameters_: Baseline refractive error values and exponential Corneal relaxation coefficients over time.  
  _Dynamic Disturbances_: Interactive toggles stimulating optical path variations and environmental noise.
* **Simulation Outputs:**  
  _Visual Wavefront Render_: Real-time 2D SFML graphical interface displaying phase front shifts across the simulated liquid crystal array.  
 _Console Telemetry_: Live diagnostic output tracking focal error metrics, phase delays, and frame rate stability.

> **A Note on Engineering Scope:**
> This is strictly a software simulation built to test math models and foster curiosity. Building physical liquid crystal adaptive lenses requires complex hardware integration, wavefront sensors, and bio-material testing far beyond simple code. This project serves as my personal sandbox to explore the underlying optical physics and challenge my C++ development skills.

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
