# Social Media Trend Analysis Tool (C Project)

## Overview
This project is a collaborative C-based system for analyzing social media trends.  
It ingests JSON-formatted posts (e.g., tweets), performs sentiment analysis, computes metrics, and displays results on a simple dashboard.

## Project Structure
- main.c → Entry point, coordinates all modules  
- api_client.c / api_client.h → Handles API interactions and JSON parsing (using `jsmn.h`)  
- dashboard_data.c / dashboard_data.h → Dashboard display and visualization logic  
- **Makefile** → Automates the build process  

## Features
- JSON parsing with JSMN (minimalistic JSON parser in C)  
- Sentiment analysis + metrics computation  
- Dashboard-style display of results  
- Modular design (each module has clear responsibilities)  

## Build & Run
1. Clone the repository:
   ```bash
   git clone https://github.com/Antonymwangi20/c-projects1.git
   cd c-projects1
   ```

2. Build the project using the provided Makefile:

   ```bash
   make
   ```

3. Run the program:

   ```bash
   ./mekill input.json
   ```

   Replace `input.json` with your JSON file containing social media posts.

4. Clean build files (optional):

   ```bash
   make clean
   ```

## Requirements

* GCC or any C99+ compatible compiler
* Basic JSON input file with social media postsor add your own twitter devs api

## Example

```bash
./mekill sample.json
```

Output: sentiment scores and trend metrics displayed on the dashboard.

```

tweet 4: juma won... london olympics...
```
