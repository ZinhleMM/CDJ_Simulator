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
    File name: MainComponent.h
    Purpose: MainComponent.h is the header file for the output main graphical user interface component, and it contains the class definitions and functions of how the main interface components are to be displayed.

    Adapted from: OtoDecks_start_topic_10 2
    Source: King, M. (2020, March 14). Dr [Lecturer]. Coursera.
            https://www.coursera.org/learn/uol-object-oriented-programming/supplement/Xc3xH/10-002-starter-code-for-topic-10
 
    NOTE:
    The commented labels/descriptions were personally written to complete this assignment.
    In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
    My code supplements the auto-generated Projucer code and the adapted code from the above cited source, which is not contained in comments as described above.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"
#include "DeckGUI.h"
//My code start
#include "CrossFader.h"
#include "DarkMode.h"
//My code end


//==============================================================================
/*
 * Class: MainComponent
 * -------------------
 *  Purpose: The main component of the application that defines all of the application controls, components and content.
 *
 *   Inherits From: AudioSource: Base class for audio sources in JUCE.
 */
class MainComponent   : public AudioAppComponent
                        
{
public:
    //==============================================================================
    /*
     * Constructor: MainComponent
     * ---------------------------
     *  Purpose: Initializes the MainComponent.
     */
    MainComponent();
    
    /*
     * Destructor: ~MainComponent
     * ----------------------------
     *  Purpose: Releases resources acquired by the MainComponent when it is destroyed.
     */
    ~MainComponent();

    //==============================================================================
    /*
     * Function: prepareToPlay
     * -----------------------
     *  Purpose: Prepares the audio system for playback.
     *
     *   Input:
     *         samplesPerBlockExpected - The expected number of samples per block.
     *         sampleRate - The audio sample rate.
     */
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    
    /*
     * Function: getNextAudioBlock
     * ---------------------------
     *  Purpose: Fills the audio buffer with the next block of audio data.
     *
     *   Input: bufferToFill - the information about the audio buffer to be filled.
     */
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    
    /*
     * Function: releaseResources
     * --------------------------
     *  Purpose: Releases audio resources when playback is finished.
     */
    void releaseResources() override;

    //==============================================================================
    /*
     * Function: paint
     * ----------------
     *  Purpose: Paints the component's graphics.
     *
     *   Input: g - The Graphics object used for painting.
     */
    void paint (Graphics& g) override;
    
    /*
     * Function: resized
     * ------------------
     *  Purpose: Called when the component is resized. Adjusts the component layout.
     */
    void resized() override;
    
    //My code start
    /*
     * Function: getIsDarkMode
     * ------------------------
     *  Purpose: Returns the current dark mode state.
     *
     *   Output: Returns true if dark mode is active, false otherwise.
     */
    bool getIsDarkMode() const
    {
        return isDarkMode;
    }
    //My code end

private:
    //==============================================================================
    AudioFormatManager formatManager;
    AudioThumbnailCache thumbCache{100};

    DJAudioPlayer player1{formatManager};
    DeckGUI deckGUI1{&player1, formatManager, thumbCache};

    DJAudioPlayer player2{formatManager};
    DeckGUI deckGUI2{&player2, formatManager, thumbCache};

    MixerAudioSource mixerSource;
    
    //My code start
    CrossFader crossFader;
    Label appDescription;
    DarkMode darkMode;
    // Adds a flag to track the current mode (dark or light)
    bool isDarkMode;
    //My code end
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
