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
    File name: CrossFader.cpp
    Purpose: CrossFader.cpp contains the implementation code for the cross-fader component to be used for audio mixing.
    Created: 6 Sep 2023 11:04:01am
    Author:  Zinhle Maurice-Mopp
 
     NOTE:
     The commented labels/descriptions were personally written to complete this assignment.
     In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
     My code supplements the auto-generated Projucer code.
  ==============================================================================
*/

#include <JuceHeader.h>
#include "CrossFader.h"

//==============================================================================
//My code start
 /*
 * Constructor: CrossFader
 * -------------------------
 *  Purpose: Initialize the CrossFader component.
 *
 *   Inputs:
 *           _player - Pointer to the DJAudioPlayer.
 *           _formatManager - AudioFormatManager for audio format management.
 */
CrossFader::CrossFader(DJAudioPlayer* _player,
                       AudioFormatManager & _formatManager
                  ) : player(_player)
{
    // Adds and makes the cross-fader slider visible
    addAndMakeVisible(crossFaderSlider);
    // Adds a listener to the cross-fader slider
    crossFaderSlider.addListener(this);
    // Sets the cross-fader slider range
    crossFaderSlider.setRange(0.0, 1.0);
    // Sets the cross-fader slider default value
    crossFaderSlider.setValue(0.5);
}

/*
 * Destructor: ~CrossFader
 * -------------------------
 *  Purpose: Releases resources when CrossFader is destroyed.
 */
CrossFader::~CrossFader() {}

/*
 * Function: paint
 * -------------------------
 *  Purpose: Handles the painting of the DeckGUI component.
 *
 *   Input:  g - Graphics object for drawing.
 */
void CrossFader::paint (Graphics& g)
{
    // Styles the cross-fader
    g.setFont (14.0f);
    juce::Colour crossFaderSliderColor(140, 0, 255);
    g.setColour(crossFaderSliderColor.withAlpha(0.7f));
    g.fillRect(crossFaderSlider.getBounds());
    g.setColour(Colours::white);
    g.drawText("Cross-fader", crossFaderSlider.getBounds().withTrimmedLeft(10).translated(15, 15), Justification::centred);
    
    // Draws an outline around the cross fader
    g.setColour(Colours::white);
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 2.0f, 1.0f);
}

/*
 * Function: resized
 * -------------------------
 *  Purpose: Sets the position and size of the cross-fader display.
 */
void CrossFader::resized()
{
   crossFaderSlider.setBounds(getLocalBounds());
}

/*
 * Function: sliderValueChanged
 * -------------------------
 *  Purpose: Handles slider value changes for volSlider, speedSlider, and posSlider.
 *
 *   Input:  slider - Pointer to the Slider component that triggered the change.
 */
void CrossFader::sliderValueChanged(Slider* slider)
{
    if (slider == &crossFaderSlider)
    {
        // Sets the gain/volume for player1 and player2
        player->setGain(slider->getValue());
        
        // Get the current value of the cross-fader slider
        double gain = crossFaderSlider.getValue();

        // Calculate the gain for player1 (1 - gain)
        double player1Gain = 1.0 - gain;
        player1.setGain(player1Gain);
        
        // Set the gain for player 2
        player2.setGain(gain);
        }
}
//My code end
