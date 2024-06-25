/*
  ==============================================================================
    
    ASSIGNMENT TITLE:
    Object Orientated Programming - Coursework 2 submission
    Final Graded Assignment - OTO Decks
    April 2023 Session
 
    AUTHOR:
    Zinhle Maurice-Mopp
    210125870
 
    //////////////////////////////////////////////////////////
 
    DESCRIPTION:
    File name: DarkMode.h
    Purpose: DarkMode.h is the header file for the cross-fader component, and it contains the class definitions and functions for the dark mode functionality, defining its interface.
    Created: 6 Sep 2023 11:04:01am
    Author:  Zinhle Maurice-Mopp
 
    NOTE:
    The commented labels/descriptions were personally written to complete this assignment.
    In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
    My code supplements the auto-generated Projucer code.
 
  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//My code start
//
/*
 * Class: DarkMode
 * --------------------
 *  Purpose: Represents a graphical component that manages dark and light mode for the GUI.
 *
 *   Inherits From:
 *                 Component - Base class for graphical components.
 *                 Button::Listener - Listener for button click events.
 */
class DarkMode  : public juce::Component,
                  public Button::Listener
{
public:
    
   /*
    * Constructor: DarkMode
    * -------------------------
    *  Purpose: Initializes the DarkMode component.
    */
    DarkMode();
    
    
    /*
     * Destructor: ~DarkMode
     * -------------------------
     *  Purpose: Releases up resources when the DarkMode is destroyed.
     */
    ~DarkMode() override;
   
    /*
     * Function: getIsDarkMode
     * -------------------------
     *  Purpose: Gets the current dark mode state.
     *
     *   Output: Returns true if dark mode is enabled, false otherwise.
     */
    bool getIsDarkMode() const
    {
        return isDarkMode;
    }

    /*
     * Function: paint
     * -------------------------
     *  Purpose: Paints the DarkMode component.
     *
     * Input: Graphics object used for painting.
     * Output: None
     */
    void paint (Graphics&) override;

    /*
     * Function: resized
     * -------------------------
     *  Purpose: Resizes the DarkMode component.
     */
    void resized() override;

    /*
     * Function: buttonClicked
     * -------------------------
     *  Purpose: Callback when the dark mode toggle button is clicked.
     *
     *  Input: button - Pointer to the button that was clicked.
     */
    void buttonClicked(Button* button) override;

private:
    
    // DarkMode toggle button
    ToggleButton darkModeButton{"DARK MODE"};

    // Adds a flag to track the current mode (dark or light)
    bool isDarkMode;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DarkMode)
};
//My code end
