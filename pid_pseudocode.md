# Pseudocode

## Generate pitch values  (This is the main logic)

```bash
FUNCTION generatePitchValue()
CREATE empty list for storing generated pitch values (pitch_values)
CREATE random number generator
SET initial pitch to 15.0  (initialPitch)
SET decay rate to 0.85     (decayRate)
SET noise level to 0.2     (noiseLevel)

# Code

FOR each iteration from 0 to 30 (Can be changed)
    initialPitch * decayRate
    GENERATE random noise between -noiseLevel to +noiseLevel (noise)
    ADD noise to initialPitch to get noisyPitch
    APPEND noisyPitch to pitch_values list
END FOR

RETURN pitch_values
```

## Main Code (This is mainly formatting)

```bash
CREATE text style with font size 50

CREATE chart with following properties:
    TITLE:
        SET text to "IMU PID Response"
        SET padding to 5.0
        CENTER the title horizontally
        SET title font size to 100
    
    GRID:
        SET bottom margin to 10% of chart height
        SET top margin to 5% of chart height
    
    X-AXIS (horizontal):
        SET type to category
        SET name to "Time"
        CENTER the axis name
        SET gap between axis and name to 60
        SET maximum value to 29
        SET axis name font size to 50
        SET axis labels font size to 40
    
    Y-AXIS (vertical):
        SET type to value
        SET name to "Pitch (°)"
        CENTER the axis name
        SET gap between axis and name to 40
        SET minimum value to 0.0
        SET maximum value to 15
        SET axis name font size to 40
        SET axis labels font size to 40
    
    DATA SERIES:
        CREATE line series named "Pitch"
        POPULATE with pitchData

CREATE image renderer with dimensions 3000x2400 pixels
APPLY "Wonderland" theme to renderer

SAVE chart as "pid.svg" file using the renderer

IF save operation successful:
    DISPLAY "Chart saved successfully"
ELSE:
    DISPLAY error message
END IF
```

