# 🔐 Face Recognition GUI App (IoT Based Door Lock)

## 📌 Project Overview
A GUI-based Face Recognition system built using Python and OpenCV.  
This project captures facial data, trains a classifier using LBPH algorithm, and performs real-time face recognition.  
It is integrated with IoT (NodeMCU/Arduino) to control a smart door locking system.

---

## 🚀 Features

- Add New User
- Capture 300 Face Images per User
- Train Face Recognition Model
- Real-time Face Detection & Recognition
- Unknown Face Detection
- Serial Communication with IoT Device
- Simple GUI Interface using Tkinter

---

## 🛠 Technologies Used

- Python 3.10
- OpenCV (opencv-contrib-python)
- Tkinter
- NumPy
- Pillow
- PySerial
- NodeMCU / Arduino

---

## 🧠 Algorithm Used

- Haar Cascade (Face Detection)
- LBPH – Local Binary Pattern Histogram (Face Recognition)

LBPH is chosen because:
- Works well for small datasets
- Fast training
- Suitable for real-time systems

---

## 📂 Project Structure

```
face-recognition-door-lock/
│
├── app-gui.py
├── create_dataset.py
├── create_classifier.py
├── Detector.py
├── requirements.txt
├── homepagepic.png
├── icon.ico
└── README.md
```

---

## ⚙ Installation Guide

### 1️⃣ Clone Repository

```
git clone https://github.com/yourusername/face-recognition-door-lock.git
cd face-recognition-door-lock
```

### 2️⃣ Create Virtual Environment

```
python -m venv venv
source venv/Scripts/activate   # For Git Bash
```

### 3️⃣ Install Dependencies

```
pip install -r requirements.txt
```

### 4️⃣ Run Application

```
python app-gui.py
```

---

## 🔄 System Workflow

1. Add User  
2. Capture Dataset (300 images)  
3. Train Classifier  
4. Perform Face Recognition  
5. Send Unlock Signal to IoT Device  

---

## 📡 IoT Output

- Recognized Face → Serial signal `1` sent (Door Unlock)
- Unknown Face → Serial signal `2` sent (Door Locked)

---

## ⚠ Limitations

- Accuracy depends on lighting conditions
- Not suitable for large-scale datasets
- Requires proper camera positioning

---

## 🔐 Privacy Notice

The dataset folder is excluded from this repository to protect biometric data and maintain repository size optimization.

---

## 📌 Future Improvements

- Add Attendance System
- Deploy as Web Application (Flask/Django)
- Improve Accuracy using Deep Learning (CNN)
- Cloud-based Authentication

---

## 👨‍💻 Author

**Saikiran Madupathi**  
BTech (Electronics & Communication Engineering)  
Python Full Stack Developer  