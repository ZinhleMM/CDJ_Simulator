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
    File name: DJAudioPlayer.cpp
    Purpose: DJAudioPlayer.cpp contains the implementation code for the audio player used in the application to enable all of the audio functionality.

    Adapted from: OtoDecks_start_topic_10 2
    Source: King, M. (2020, March 14). Dr [Lecturer]. Coursera.
            https://www.coursera.org/learn/uol-object-oriented-programming/supplement/Xc3xH/10-002-starter-code-for-topic-10
 
    NOTE:
    The commented labels/descriptions were personally written to complete this assignment.
    In addition the code contained in the "//My code start" and "//My code end" comments is the code I wrote myself.
    My code supplements the auto-generated Projucer code and the adapted code from the above cited source, which is not contained in comments as described above.
 
  ==============================================================================
*/

#include "DJAudioPlayer.h"

/*
 * Constructor: DJAudioPlayer
 * -------------------------
 *  Purpose: Initializes the DJAudioPlayer component with the given AudioFormatManager.
 *
 *   Input:  _formatManager - A reference to the AudioFormatManager used for audio file handling.
 */
DJAudioPlayer::DJAudioPlayer(AudioFormatManager& _formatManager)
: formatManager(_formatManager)
{

}

/*
 * Destructor: ~DJAudioPlayer
 * --------------------------
 *  Purpose: Releases resources when the DJAudioPlayer is destroyed.
 */
DJAudioPlayer::~DJAudioPlayer()
{

}

/*
 * Function: prepareToPlay
 * -----------------------
 *  Purpose: Prepares the DJAudioPlayer for playback.
 *
 *   Inputs:  samplesPerBlockExpected - The number of audio samples per block expected for playback.
 *           sampleRate - The sample rate of the audio.
 */
void DJAudioPlayer::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
    resampleSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

/*
 * Function: getNextAudioBlock
 * ---------------------------
 *  Purpose: Fills the given buffer with the next audio block from the player.
 *
 *   Input:  bufferToFill - An AudioSourceChannelInfo object containing the buffer to fill.
 */
void DJAudioPlayer::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    resampleSource.getNextAudioBlock(bufferToFill);
}

/*
 * Function: releaseResources
 * --------------------------
 *  Purpose: Releases any resources aquired by the DJAudioPlayer.
 */
void DJAudioPlayer::releaseResources()
{
    transportSource.releaseResources();
    resampleSource.releaseResources();
}

/*
 * Function: loadURL
 * -----------------
 *  Purpose: Loads an audio file from the given URL and prepares it for playback.
 *
 *   Input:  audioURL - The URL of the audio file to load.
 */
void DJAudioPlayer::loadURL(URL audioURL)
{
    auto* reader = formatManager.createReaderFor(audioURL.createInputStream(false));
    if (reader != nullptr)
    {
        std::unique_ptr<AudioFormatReaderSource> newSource (new AudioFormatReaderSource (reader, true));
        transportSource.setSource (newSource.get(), 0, nullptr, reader->sampleRate);
        readerSource.reset (newSource.release());
    }
}

/*
 * Function: setGain
 * -----------------
 *  Purpose: Sets the gain (volume) of the audio playback.
 *
 *   Input:  gain - The new gain value (between 0 and 2.0).
 */
void DJAudioPlayer::setGain(double gain)
{
    if (gain < 0 || gain > 2.0)
    {

    }
    else {
        transportSource.setGain(gain);
    }
}

/*
 * Function: setSpeed
 * ------------------
 *  Purpose: Sets the playback speed (resampling ratio) of the audio.
 *
 *   Input:  ratio - The new resampling ratio (between 0 and 5.0).
 */
void DJAudioPlayer::setSpeed(double ratio)
{
    if (ratio < 0 || ratio > 5.0)
    {

    }
    else {
        resampleSource.setResamplingRatio(ratio);
    }
}

/*
 * Function: setPosition
 * ---------------------
 *  Purpose: Sets the playback position to the specified time in seconds.
 *
 *   Input:  posInSecs - The new playback position in seconds.
 */
void DJAudioPlayer::setPosition(double posInSecs)
{
    transportSource.setPosition(posInSecs);
}

/*
 * Function: setPositionRelative
 * -----------------------------
 *  Purpose: Sets the playback position relative to the total duration as a fraction.
 *
 *   Input:  pos - The new playback position as a fraction of the total duration (between 0 and 1.0).
 */
void DJAudioPlayer::setPositionRelative(double pos)
{
     if (pos < 0 || pos > 1.0)
     {

    }
    else {
        double posInSecs = transportSource.getLengthInSeconds() * pos;
        setPosition(posInSecs);
    }
}

/*
 * Function: start
 * ---------------
 *  Purpose: Starts playback of the audio.
 */
void DJAudioPlayer::start()
{
    transportSource.start();
}

/*
 * Function: stop
 * --------------
 *  Purpose: Stops playback of the audio.
 */
void DJAudioPlayer::stop()
{
    transportSource.stop();
}

/*
 * Function: getPositionRelative
 * -----------------------------
 *  Purpose: Gets the current playback position as a fraction of the total duration.
 *
 *   Output: Returns the current playback position as a fraction (between 0 and 1.0).
 */
double DJAudioPlayer::getPositionRelative()
{
    return transportSource.getCurrentPosition() / transportSource.getLengthInSeconds();
}
