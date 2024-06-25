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
    File name: WaveformDisplay.h
    Purpose: WaveformDisplay.h is the header file for the waveform visualization, and it contains the class definitions and functions of how the waveform visualization is to be displayed.

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

//==============================================================================
/*
 * Class: WaveformDisplay
 * -------------------------
 *  Purpose: Represents a graphical component for displaying audio waveforms.
 *
 *  Inherits From:
 *                Component - Base class for graphical components.
 *                ChangeListener - Listener for change events.
 */
class WaveformDisplay : public Component, public ChangeListener
{
public:
    /*
     * Constructor: WaveformDisplay
     * -------------------------
     *  Purpose: Initializes the WaveformDisplay component.
     *
     *   Inputs:
     *         formatManagerToUse - AudioFormatManager for loading audio files.
     *         cacheToUse - AudioThumbnailCache for caching audio thumbnails.
     */
    WaveformDisplay(AudioFormatManager& formatManagerToUse, AudioThumbnailCache& cacheToUse);

    /*
     * Destructor: ~WaveformDisplay
     * -------------------------
     * Purpose: Cleans up resources when WaveformDisplay is destroyed.
     */
    ~WaveformDisplay();

    /*
     * Function: paint
     * -------------------------
     * Purpose: Paints the waveform display component.
     *
     *   Input:  g - Graphics object for drawing.
     */
    void paint(Graphics& g) override;

    /*
     * Function: resized
     * -------------------------
     *  Purpose: Handles resizing of the waveform display component.
     */
    void resized() override;

    /*
     * Function: changeListenerCallback
     * -------------------------
     *  Purpose: Callback function called when a change occurs in the audio thumbnail.
     *
     *   Input:
     *           source - Pointer to the ChangeBroadcaster that triggered the change.
     */
    
    void changeListenerCallback(ChangeBroadcaster* source) override;

    /*
     * Function: loadURL
     * -------------------------
     *  Purpose: Loads an audio file from the specified URL and displays its waveform.
     *
     * Input: audioURL - URL of the audio file to load and display.
     */
    void loadURL(URL audioURL);

    /*
     * Function: setPositionRelative
     * -------------------------
     *  Purpose: Sets the current position of the waveform display relative to the audio.
     *
     *   Input: pos - Relative position within the audio (0.0 to 1.0).
     */
    void setPositionRelative(double pos);

private:
    // Stores the audio thumbnail
    AudioThumbnail audioThumb;
    // Indicates whether an audio file is loaded
    bool fileLoaded;
    // Current position within the audio
    double position;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveformDisplay)
};

