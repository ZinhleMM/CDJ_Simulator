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
    File name: DeckGUI.cpp
    Purpose: DeckGUI.cpp contains the implementation code for the graphical user interface for the deck component.

    Adapted from: OtoDecks_start_topic_10 2
    Source: King, M. (2020, March 14). Dr [Lecturer]. Coursera.
            https://www.coursera.org/learn/uol-object-oriented-programming/supplement/Xc3xH/10-002-starter-code-for-topic-10
 
    NOTE:
    The commented labels/descriptions were personally written to complete this assignment.
    In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
    My code supplements the auto-generated Projucer code and the adapted code from the above cited source, which is not
    contained in comments as described above.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "DeckGUI.h"

//==============================================================================

/*
 * Constructor: DeckGUI
 * -------------------------
 *  Purpose: Initializes the DeckGUI component.
 *
 *   Input:
 *         _player: Pointer to the DJAudioPlayer.
 *         formatManagerToUse: AudioFormatManager for the waveform display.
 *         cacheToUse: AudioThumbnailCache for the waveform display.
 */
DeckGUI::DeckGUI(DJAudioPlayer* _player,
                AudioFormatManager &     formatManagerToUse,
                AudioThumbnailCache &     cacheToUse
           ) : player(_player),
               waveformDisplay(formatManagerToUse, cacheToUse), darkMode()
{
    // Adds and makes the Deck GUI components visible
    addAndMakeVisible(playButton);
    addAndMakeVisible(stopButton);
    addAndMakeVisible(loadButton);
    addAndMakeVisible(volSlider);
    addAndMakeVisible(speedSlider);
    addAndMakeVisible(posSlider);
    addAndMakeVisible(waveformDisplay);
    
    // Adds listeners to buttons and sliders
    playButton.addListener(this);
    stopButton.addListener(this);
    loadButton.addListener(this);
    
    // Sets slider ranges
    volSlider.addListener(this);
    speedSlider.addListener(this);
    posSlider.addListener(this);
    
    //My code start
    // Set slider ranges
    volSlider.setRange(0.0, 2.0);
    speedSlider.setRange(0.0, 5.0);
    posSlider.setRange(0.0, 1.0);
    //My code end

    // Starts a timer for periodic updates
    startTimer(500);
    
    //My code start
    volSlider.setSliderStyle(juce::Slider::LinearVertical);
    posSlider.setSliderStyle(juce::Slider::Rotary);
    // Initializes the track name label
    addAndMakeVisible(trackName);
    speedSlider.setValue(1.0);
    volSlider.setValue(1.0);
    //My code end

}

/*
 * Destructor: ~DeckGUI
 * -------------------------
 *  Purpose: Releases resources when DeckGUI is destroyed.
 */
DeckGUI::~DeckGUI()
{
    stopTimer();
}

/*
 * Function: paint
 * -------------------------
 *  Purpose: Handles the painting of the DeckGUI component.
 *
 *   Input:  g - Graphics object for drawing.
 */
void DeckGUI::paint(Graphics& g)
{
    //My code start
    // Styles the playButton
    playButton.setColour(TextButton::buttonColourId, Colour(0, 255, 9));
    g.setColour(Colours::white);
    g.drawRect(playButton.getBounds(), 2);
    
    // Styles the stopButton
    stopButton.setColour(TextButton::buttonColourId, Colour(0, 90, 255));
    g.setColour(Colours::white);
    g.drawRect(stopButton.getBounds(), 2);

    // Styles the loadButton
    loadButton.setColour(TextButton::buttonColourId, Colour(225, 121, 0));
    g.setColour(Colours::white);
    g.drawRect(loadButton.getBounds(), 2);
    
   // Styles and labels the volSlider
    juce::Colour volSliderColor(5, 188, 170);
    g.setColour(volSliderColor.withAlpha(0.7f));
    g.fillRect(volSlider.getBounds());
    g.setColour(Colours::white);
    g.setFont(14.0f);
    g.drawText("Fader", volSlider.getBounds().withTrimmedLeft(10).translated(0, 20), Justification::left);
    g.drawText("(Volume)", volSlider.getBounds().withTrimmedLeft(10).translated(0, 40), Justification::left);
    g.setColour(Colours::white);
    g.drawRoundedRectangle(volSlider.getBounds().toFloat(), 2.0f, 1.0f);

    // Styles and labels the speedSlider
    juce::Colour speedSliderColor(225, 0, 242);
    g.setColour(speedSliderColor.withAlpha(0.7f));
    g.fillRect(speedSlider.getBounds());
    g.setColour(Colours::white);
    g.drawText("Speed", speedSlider.getBounds().withTrimmedLeft(10).translated(0, 15), Justification::centred);
    g.setColour(Colours::white);
    g.drawRoundedRectangle(speedSlider.getBounds().toFloat(), 2.0f, 1.0f);

    // Styles and labels the posSlider
    juce::Colour posSliderColor(0, 66, 255);
    g.setColour(posSliderColor.withAlpha(0.7f));
    g.fillRect(posSlider.getBounds());
    g.setColour(Colours::white);
    g.drawText("Jog Wheel - Track Position", posSlider.getBounds().withTrimmedLeft(10).translated(0, 110), Justification::centred);
    g.setColour(Colours::white);
    g.drawRoundedRectangle(posSlider.getBounds().toFloat(), 2.0f, 1.0f);

    // Styles the trackName display component
    juce::Colour trackNameColor(16, 233, 246);
    g.setColour(trackNameColor.withAlpha(0.6f));
    g.fillRect(trackName.getBounds());
    g.setColour(Colours::white);
    g.setFont(14.0f);
    trackName.setJustificationType(juce::Justification::centred);
    g.setColour(Colours::white);
    g.drawRoundedRectangle(trackName.getBounds().toFloat(), 2.0f, 1.0f);
    
    // Draws an outline around the GUI component
    g.setColour(Colours::white);
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 6.0f, 3.0f);
    //My code start
}

/*
 * Function: resized
 * -------------------------
 *  Purpose: Sets the position and size of the Deck GUI components when the component is resized.
 */
void DeckGUI::resized()
{
    //My code start
    // Sets the position and size of the Deck GUI components
    posSlider.setBounds(0, 0, 400, 250);
    loadButton.setBounds(0, 250, 50, 50);
    trackName.setBounds(50, 250, 250, 50);
    volSlider.setBounds(300, 250, 100, 200);
    playButton.setBounds(0, 300, 50, 50);
    waveformDisplay.setBounds(50, 300, 250, 100);
    stopButton.setBounds(0, 350, 50, 50);
    speedSlider.setBounds(0, 400, 300, 50);
    //My code end
}

/*
 * Function: buttonClicked
 * -------------------------
 *  Purpose: Handles button click events for playButton, stopButton, and loadButton.
 *
 *   Input:  button - The button that was clicked.
 */
void DeckGUI::buttonClicked(Button* button)
{
    // Handles button click events
    if (button == &playButton)
    {
        player->start();
    }
     if (button == &stopButton)
    {
        player->stop();

    }
       if (button == &loadButton)
    {
        auto fileChooserFlags =
        FileBrowserComponent::canSelectFiles;
        fChooser.launchAsync(fileChooserFlags, [this](const FileChooser& chooser)
        {
            player->loadURL(URL{chooser.getResult()});
            waveformDisplay.loadURL(URL{chooser.getResult()});
                        // Updates the track title when loading a new file
                        fileName = chooser.getResult().getFileName();
                        trackName.setText(fileName, juce::dontSendNotification);
        });
    }
}
    
/*
 * Function: sliderValueChanged
 * -------------------------
 *  Purpose: Handles slider value changes for volSlider, speedSlider, and posSlider.
 *
 *   Input:  slider - The slider whose value changed.
 */
 void DeckGUI::sliderValueChanged (Slider *slider)
 {
     // Handles slider value changes
     if (slider == &volSlider)
     {
         player->setGain(slider->getValue());
     }

     if (slider == &speedSlider)
     {
         player->setSpeed(slider->getValue());
     }
     
     if (slider == &posSlider)
     {
         player->setPositionRelative(slider->getValue());
     }
     
 }

/*
 * Function: isInterestedInFileDrag
 * -------------------------
 *  Purpose: Checks if the component is interested in a file drag event.
 *
 *   Input:  files - An array of file paths being dragged.
 *
 *   Output: true if interested, false otherwise.
 */
 bool DeckGUI::isInterestedInFileDrag (const StringArray &files)
 {
   return true;
 }

/*
 * Function: filesDropped
 * -------------------------
 *  Purpose: Handles file dropping events and loads a file if a single file is dropped.
 *
 *   Input:
 *           files - An array of file paths that were dropped.
 *           x, y - The coordinates of the drop event.
 */
 void DeckGUI::filesDropped (const StringArray &files, int x, int y)
 {
   if (files.size() == 1)
   {
     player->loadURL(URL{File{files[0]}});
   }
 }

/*
 * Function: timerCallback
 * -------------------------
 *  Purpose: Callback function called by the timer for periodic updates.
 */
 void DeckGUI::timerCallback()
 {
     waveformDisplay.setPositionRelative(player->getPositionRelative());
 }
