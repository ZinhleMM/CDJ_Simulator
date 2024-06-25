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
    File name: WaveformDisplay.cpp
    Purpose: WaveformDisplay.cpp contains the implementation code for the audio waveforms component to be displayed in the deck component.

    Adapted from: OtoDecks_start_topic_10 2
    Source: King, M. (2020, March 14). Dr [Lecturer]. Coursera. https://www.coursera.org/learn/uol-object-oriented-programming/supplement/Xc3xH/10-002-starter-code-for-topic-10
     
    NOTE:
    The commented labels/descriptions were personally written to complete this assignment.
    In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
    My code supplements the auto-generated Projucer code and the adapted code from the above cited source, which is not contained in comments as described above.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "WaveformDisplay.h"

//==============================================================================
/*
 * Constructor: WaveformDisplay
 * -------------------------
 *  Purpose: Initialize the WaveformDisplay component.
 *
 *   Inputs:
 *           formatManagerToUse: AudioFormatManager for audio file formats.
 *           cacheToUse: AudioThumbnailCache for caching audio thumbnails.
 */
WaveformDisplay::WaveformDisplay(AudioFormatManager& formatManagerToUse,
                                 AudioThumbnailCache& cacheToUse)
    : audioThumb(1000, formatManagerToUse, cacheToUse),
      fileLoaded(false),
      position(0)
{
    // Adds this component as a change listener to the audio thumbnail
    audioThumb.addChangeListener(this);
}

/*
 * Destructor: ~WaveformDisplay
 * -------------------------
 *  Purpose: Releases resources when WaveformDisplay is destroyed.
 */
WaveformDisplay::~WaveformDisplay()
{

}

/*
 * Function: paint
 * -------------------------
 *  Purpose: Handles the painting of the DeckGUI component.
 *
 *   Input:  g - Graphics object for drawing.
 */
void WaveformDisplay::paint(Graphics& g)
{
    //My code start
    // Draws an outline around the waveform display
    g.setColour(Colours::white);
    g.drawRect(getLocalBounds(), 1);

    // Sets the color for the waveform display
    juce::Colour waveformDisplayColor(255, 242, 0);
    g.setColour(waveformDisplayColor);
    //My code end
    
    if (fileLoaded)
    {
        // Draws the audio waveform
        audioThumb.drawChannel(g, getLocalBounds(), 0, audioThumb.getTotalLength(), 0, 1.0f);

        // Highlights the current track position
        g.setColour(Colours::lightgreen);
        g.drawRect(position * getWidth(), 0, getWidth() / 20, getHeight());
    }
    else
    {
        // Displays a message if no file is loaded
        g.setFont(20.0f);
        g.drawText("File not loaded...", getLocalBounds(),Justification::centred, true);
    }
}

/*
 * Function: resized
 * -------------------------
 *  Purpose: Sets the position and size of the waveform display when the component is resized.
 */
void WaveformDisplay::resized()
{

}

/*
 * Function: loadURL
 * -------------------------
 *  Purpose: Loads an audio file from a URL and update the waveform display.
 *
 *   Input:  audioURL - The URL of the audio file to load.
 */
void WaveformDisplay::loadURL(URL audioURL)
{
    // Clears the existing audio thumbnail
    audioThumb.clear();

    // Sets the source from the provided URL
    fileLoaded = audioThumb.setSource(new URLInputSource(audioURL));

    // Repaints the waveform display if a file is successfully loaded
    if (fileLoaded)
    {
        repaint();
    }
}

/*
 * Function: changeListenerCallback
 * -------------------------
 *  Purpose: Callback function called when the audio thumbnail changes.
 *
 *   Input:  source - The source of the change event.
 */
void WaveformDisplay::changeListenerCallback(ChangeBroadcaster* source)
{

    // Repaints the waveform display to reflect changes in the audio thumbnail
    repaint();
}

/*
 * Function: setPositionRelative
 * -------------------------
 *  Purpose: Set the current position of the waveform display.
 *
 *   Input:  pos - The relative position (0.0 to 1.0) of the audio file.
 */
void WaveformDisplay::setPositionRelative(double pos)
{

    // Updates the position and repaints the waveform display to refelct changes in
    if (pos != position)
    {
        position = pos;
        repaint();
    }
}
