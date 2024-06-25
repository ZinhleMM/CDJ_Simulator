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
    File name: CrossFader.h
    Purpose: CrossFader.h is the header file for the cross-fader component, and it contains the class definitions and functions of how the related audio is to be output.
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
#include "DJAudioPlayer.h"

//==============================================================================
/*
 * Class: CrossFader
 * -----------------
 * Purpose: Represents a crossfader component used for audio mixing.
 *  Inherits From: Component - Base class for graphical components.
 *                 Button::Listener - Listener for button click events.
 */
class CrossFader  : public juce::Component,
                    public juce::Slider::Listener
{
public:
   /*
    * Constructor: CrossFader
    * -------------------------
    *  Purpose: Initializes the CrossFader component.
    *
    *   Inputs:
    *          player - Pointer to the DJAudioPlayer instance.
    *          formatManager - Reference to the AudioFormatManager for audio format handling.
    */
    CrossFader(DJAudioPlayer* player, AudioFormatManager& formatManager);

    /*
     * Destructor: ~CrossFader
     * -------------------------
     *  Purpose: Realeases resources when the CrossFader is destroyed.
     */
    ~CrossFader();

    /*
     * Function: paint
     * -------------------------
     *  Purpose: Handles the painting of the cross-fader component.
     *
     *   Input:  g - Graphics object for drawing.
     */
    void paint (Graphics& g) override;

    /*
     * Function: resized
     * -------------------------
     *  Purpose: Handles resizing of the cross-fader component.
     */
    void resized() override;

    /*
     * Function: sliderValueChanged
     * ----------------------------
     *  Purpose: Handles changes in the cross-fader slider's value.
     *
     *   Input:  slider: Pointer to the Slider component that triggered the change.
     */
    void sliderValueChanged(Slider* slider) override;

private:
    // The cross-fader slider
    Slider crossFaderSlider;
    // Pointer to the DJAudioPlayer
    DJAudioPlayer* player;
    // Audio format manager for loading audio files
    AudioFormatManager formatManager;
    // DJAudioPlayer instance for deck 1
    DJAudioPlayer player1{formatManager};
    // DJAudioPlayer instance for deck 2
    DJAudioPlayer player2{formatManager};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CrossFader)
};

//My code end
