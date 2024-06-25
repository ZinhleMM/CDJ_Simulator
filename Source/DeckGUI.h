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
    File name: DeckGUI.h
    Purpose: DeckGUI.h is the header file for the graphical user interface for the deck component, and it contains the class definitions and functions of how the component is to be displayed.

    Adapted from: OtoDecks_start_topic_10 2
    Source: King, M. (2020, March 14). Dr [Lecturer]. Coursera. https://www.coursera.org/learn/uol-object-oriented-programming/supplement/Xc3xH/10-002-starter-code-for-topic-10
 
    NOTE:
    The commented labels/descriptions were personally written to complete this assignment.
    In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
    My code supplements the auto-generated Projucer code and the adapted code from the above cited source, which is not contained in comments as described above.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DJAudioPlayer.h"
#include "WaveformDisplay.h"
#include "DarkMode.h"

//==============================================================================

/*
 * Class: DeckGUI
 * --------------------
 * Purpose: Represents a graphical user interface for controlling audio playback and display.
 *  Inherits From: Component - Base class for graphical components.
 *                 Button::Listener - Listener for button click events.
 *                 Slider::Listener - Listener for slider value change events.
 *                 FileDragAndDropTarget - Listener for file drag-and-drop events.
 *                 Timer - Timer callback for periodic updates.
 */
class DeckGUI : public Component,
                public Button::Listener,
                public Slider::Listener,
                public FileDragAndDropTarget,
                public Timer
{
public:
    /*
     * Constructor: DeckGUI
     * -------------------------
     *  Purpose: Initializes the DeckGUI component.
     *
     *   Inputs:
     *           player: Pointer to the DJAudioPlayer.
     *           formatManagerToUse: AudioFormatManager for the waveform display.
     *           cacheToUse: AudioThumbnailCache for the waveform display.
     */
    DeckGUI(DJAudioPlayer* player,
            AudioFormatManager& formatManagerToUse,
            AudioThumbnailCache& cacheToUse);
    
    /*
     * Destructor: ~DeckGUI
     * -------------------------
     *  Purpose: Releases resources when DeckGUI is destroyed.
     */
    ~DeckGUI();

    void paint(Graphics&) override;
    void resized() override;

    /*
     * Function: buttonClicked
     * -------------------------
     *  Purpose: Handles button click events.
     *
     *   Input: button - The button that was clicked.
     */
    void buttonClicked(Button* button) override;

    /*
     * Function: sliderValueChanged
     * -------------------------
     *  Purpose: Handles slider value changes.
     *
     *   Input:  slider - Pointer to the Slider component that changed.
     */
    void sliderValueChanged(Slider* slider) override;

    /*
     * Function: isInterestedInFileDrag
     * -------------------------
     *  Purpose: Check if the component is interested in file drag-and-drop events.
     *
     *   Input:  files - An array of file paths being dragged.
     *
     *   Output: Returns true if interested; false otherwise.
     */
    bool isInterestedInFileDrag(const StringArray& files) override;

    /*
     * Function: filesDropped
     * -------------------------
     *  Purpose: Handles files being dropped onto the component.
     *
     *   Inputs:
     *           files - An array of file paths that were dropped.
     *            x - The x-coordinate where the files were dropped.
     *            y - The y-coordinate where the files were dropped.
     */
    void filesDropped(const StringArray& files, int x, int y) override;

    /*
     * Function: timerCallback
     * -------------------------
     *  Purpose: Callback function called by the timer for periodic updates.
     *
     */
    void timerCallback() override;

    //My code start
    /*
     * Function: loadURL
     * -------------------------
     *  Purpose: Loads an audio file from a given URL.
     *
     *   Input:  audioURL - The URL of the audio file to load.
     */
    void loadURL(URL audioURL);
    //My code end

    bool getIsDarkMode() const
    {
        return isDarkMode;
    }

private:

    TextButton playButton{"PLAY"};
    TextButton stopButton{"STOP"};
    TextButton loadButton{"LOAD"};

    Slider volSlider;
    Slider speedSlider;
    Slider posSlider;

    //My code start
    Label trackName;
    juce::String fileName;
    //My code end

    FileChooser fChooser{"Select a file..."};

    DJAudioPlayer* player;
    WaveformDisplay waveformDisplay;

    //My code start
    // DarkMode object for managing dark mode UI style
    DarkMode darkMode;
    // Adds a flag to track the current mode (dark or light)
    bool isDarkMode;
    //My code end

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DeckGUI)
};
