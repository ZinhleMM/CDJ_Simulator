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
    File name: DarkMode.cpp
    Purpose: DarkMode.cpp contains the implementation code for the dark mode feature for the application's user interface.
    Created: 6 Sep 2023 11:04:01am
    Author:  Zinhle Maurice-Mopp
 
     NOTE:
     The commented labels/descriptions were personally written to complete this assignment.
     In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
     My code supplements the auto-generated Projucer code.
 
  ==============================================================================
*/

#include "DarkMode.h"

//My code start
/*
* Constructor: CrossFader
* -------------------------
*  Purpose: Initialize the CrossFader component.
*/
DarkMode::DarkMode()
{
    // Sets default to dark mode
    isDarkMode = true;
    addAndMakeVisible(darkModeButton);
    // Adds a listener to the dark mode button
    darkModeButton.addListener(this);
    // Sets the dark mode button default state
    darkModeButton.setToggleState(isDarkMode, juce::dontSendNotification);
}

/*
 * Destructor: ~DarkMode
 * -------------------------
 *  Purpose: Releases resources when DarkMode is destroyed.
 */
DarkMode::~DarkMode()
{
}

/*
 * Function: paint
 * -------------------------
 *  Purpose: Handles the painting of the DeckGUI component.
 *
 *   Input:  g - Graphics object for drawing.
 */
void DarkMode::paint (Graphics& g)
{
    // Draws an outline around the dark mode button
    g.setColour(Colours::white);
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 2.0f, 1.0f);
}
/*
 * Function: resized
 * -------------------------
 *  Purpose: Sets the position and size of the dark mode button component.
 */
void DarkMode::resized()
{
    darkModeButton.setBounds(getLocalBounds());
}

/*
 * Function: buttonClicked
 * -------------------------
 *  Purpose: Handles button click events for playButton, stopButton, and loadButton.
 *
 *   Input:  button - The button that was clicked.
 */
void DarkMode::buttonClicked(Button* button) 
{
    if (button == &darkModeButton)
    {
        isDarkMode = darkModeButton.getToggleState();
        repaint();
    }
}
//My code end
