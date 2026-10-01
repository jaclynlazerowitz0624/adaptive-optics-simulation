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
* **AP Physics 2 & Honors Physics 1:** Applied physical optics principles—specifically Snell's Law, refractive index transitions, and wave phase shifts—to render dynamic light distortion across optical media.
* **AP Calculus AB:** Leveraged continuous rates of change and exponential decay models (`R(t) = R0 * e^(-λt)`) to simulate post-Ortho-K corneal relaxation over time.
* **AP Statistics:** Utilized probability distributions to inject realistic Gaussian noise and spatial perturbations into array nodes, modeling physical optical sensor noise.
* **AP Computer Science A & Independent Java/C++:** Translated complex mathematical algorithms into modular, object-oriented code, managing real-time data flow inside the C++ execution loop.
* **Regents Chemistry & Biology:** Grounded the corneal relaxation decay models in biological tissue behavior and biomechanical stress recovery concepts.

### Alignment with Electrical & Computer Engineering
* **Signal Processing & Systems:** Mapping real-time wavefront phase deviations directly mirrors spatial signal modeling, digital noise filtering, and phase delay processing.
* **Multivariable Calculus & Vector Analysis:** Computing directional rate-of-change across wavefront matrices prepares for 3D field calculations and sub-pixel resolution routines.

### Future Scope & Explorations
* **Wavefront Sensing Integration:** Simulating active sensor feedback loops to dynamically detect phase aberrations.
* **Sub-Pixel Interpolation:** Enhancing visual rendering resolution for higher-fidelity wavefront display.
* **Phase Correction Algorithms:** Implementing real-time feedback loops to calculate inverse phase delays across simulated liquid crystal matrix elements.
