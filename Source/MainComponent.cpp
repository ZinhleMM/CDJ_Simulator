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
    File name: MainComponent.cpp
    Purpose: MainComponent.cpp contains the implementation code for the output graphical user interface of all of the visible components of the application.
    Adapted from: OtoDecks_start_topic_10 2
    Source: King, M. (2020, March 14). Dr [Lecturer]. Coursera.
            https://www.coursera.org/learn/uol-object-oriented-programming/supplement/Xc3xH/10-002-starter-code-for-topic-10
 
    NOTE:
    The commented labels/descriptions were personally written to complete this assignment.
    In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
    My code supplements the auto-generated Projucer code and the adapted code from the above cited source, which is notcontained in comments as described above.

  ==============================================================================
*/


#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
/*
 * Function: MainComponent::MainComponent
 * -------------------------
 *  Purpose: Constructor for the MainComponent class
 *           Initializes objects of the MainComponent class, setting the initial state of the objects, allocating resources,
 *           and performing any necessary setup when an object is created
 *
 *   Input: None
 */
: crossFader(&player1, formatManager),
  darkMode()
{
    setSize (800, 600);

    if (RuntimePermissions::isRequired (RuntimePermissions::recordAudio)
        && ! RuntimePermissions::isGranted (RuntimePermissions::recordAudio))
    {
        RuntimePermissions::request (RuntimePermissions::recordAudio,
                                     [&] (bool granted) { if (granted)  setAudioChannels (2, 2); });
    }
    else
    {
        setAudioChannels (0, 2);
    }

    addAndMakeVisible(deckGUI1);
    addAndMakeVisible(deckGUI2);
    //My code start
    addAndMakeVisible(crossFader);
    addAndMakeVisible(appDescription);
    addAndMakeVisible(darkMode);
    //My code end

    formatManager.registerBasicFormats();
}

MainComponent::~MainComponent()
/*
 * Function: MainComponent::~MainComponent
 * -------------------------
 *  Purpose: Destructor for the MainComponent class.
 *           Ensures that resources acquired by the objects are released.
 *
 *   Input: None.
 */
{
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
/*
 * Function: MainComponent::prepareToPlay
 * -------------------------
 *  Purpose: Prepares the audio components for playback.
 *
 *   Input:
 *     - samplesPerBlockExpected: Number of samples per audio block.
 *     - sampleRate: The sample rate of the audio stream.

 */
{
    player1.prepareToPlay(samplesPerBlockExpected, sampleRate);
    player2.prepareToPlay(samplesPerBlockExpected, sampleRate);
    
    mixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);

    mixerSource.addInputSource(&player1, false);
    mixerSource.addInputSource(&player2, false);
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
/*
 * Function: MainComponent::getNextAudioBlock
 * -------------------------
 *  Purpose: Fills the audio buffer with the next audio block.
 *
 *   Input:
 *     - bufferToFill: Information about the buffer to fill.
 */
{
    mixerSource.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
/*
 * Function: MainComponent::releaseResources
 * -------------------------
 *  Purpose: Releases audio resources when done with audio processing.
 */
{
    player1.releaseResources();
    player2.releaseResources();
    mixerSource.releaseResources();
}

//==============================================================================
/*
 * Function: paint
 * -------------------------
 * Purpose: Renders the component's appearance.
 *
 * Input:  g - The Graphics object used for painting.
 */
void MainComponent::paint (Graphics& g)
{
    //My code start
    // Clears the background
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // Checks the state of the dark mode toggle button
    if (darkMode.getIsDarkMode())
    {
        // Sets the background to black in dark mode
        g.fillAll(Colours::black);
        // Sets the text color to white in dark mode
        g.setColour(Colours::white);
        repaint();
    }
    else
    {
        // Sets the background to white in light mode
        g.fillAll(Colours::white);
        repaint();
    }

    //Sets the app description label style and text
    juce::Colour appDescriptionColor(32, 146, 203);
    g.setColour(appDescriptionColor.withAlpha(0.7f));
    g.fillRect(appDescription.getBounds());
    appDescription.setText("OTO Decks by Zinhle Maurice-Mopp (210125870)", NotificationType::dontSendNotification);
    appDescription.setJustificationType(Justification::centred);
    Font appDescriptionFont(20.0f);
    appDescriptionFont.setStyleFlags(Font::italic);
    appDescription.setFont(appDescriptionFont);
    
    // Draws an outline around the main component
    g.setColour(Colours::white);
    g.drawRoundedRectangle(getLocalBounds().toFloat(), 6.0f, 3.0f);
    //My code end
}

/*
 * Function: MainComponent::resized
 * --------------------------------
 *  Purpose: Sets the position and size of the GUI components,
 *           including the app description label, deck GUIs, dark mode toggle button,
 *           and crossfader slider.
 */
void MainComponent::resized()
{
    //My code start
    //Sets the components position and size
    appDescription.setBounds(0, 0, 800, 100);
    deckGUI1.setBounds(0, getHeight()/6, getWidth()/2, getHeight()*0.75);
    deckGUI2.setBounds(getWidth()/2, getHeight()/6, getWidth()/2, getHeight()*0.75);
    darkMode.setBounds(650, 0, 150, 50);
    crossFader.setBounds(300, 550, 200, 50);
    //My code end
}
