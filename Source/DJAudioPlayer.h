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
    File name: DJAudioPlayer.h
    Purpose: DJAudioPlayer.h is the header file for the audio player, and it contains the class definitions and functions of how the audio is to be output.

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

/*
 * Class: DJAudioPlayer
 * --------------------
 *  Purpose: Represents an audio player that can load, play, and control audio files.
 *
 *   Inherits From: AudioSource: Base class for audio sources in JUCE.
 */
class DJAudioPlayer : public AudioSource {
public:
    //==============================================================================
    /*
     * Constructor: DJAudioPlayer
     * --------------------------
     *  Purpose: Initializes the DJAudioPlayer with the given AudioFormatManager.
     *
     *   Input: _formatManager - The AudioFormatManager for handling audio formats.
     */
    DJAudioPlayer(AudioFormatManager& _formatManager);

    /*
     * Destructor: ~DJAudioPlayer
     * ---------------------------
     *  Purpose: Releases resources when the DJAudioPlayer is destroyed.
     */
    ~DJAudioPlayer();

    /*
     * Function: prepareToPlay
     * -----------------------
     *  Purpose: Prepares the audio player for playback.
     *
     *   Inputs:
     *           samplesPerBlockExpected - The expected number of samples per block.
     *           sampleRate - The audio sample rate.
     */
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    /*
     * Function: getNextAudioBlock
     * ---------------------------
     *  Purpose: Fills the audio buffer with the next block of audio data.
     *
     *   Input:  bufferToFill - Information about the audio buffer to be filled.
     */
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;

    /*
     * Function: releaseResources
     * --------------------------
     *  Purpose: Releases audio resources when playback is finished.
     */
    void releaseResources() override;

    /*
     * Function: loadURL
     * -----------------
     *  Purpose: Loads an audio file from the given URL for playback.
     *
     *   Input: audioURL - The URL of the audio file to load.
     */
    void loadURL(URL audioURL);

    /*
     * Function: setGain
     * -----------------
     *  Purpose: Sets the playback gain (volume) for the audio player.
     *
     *   Input:  gain - The desired gain level (0.0 to 1.0).
     */
    void setGain(double gain);

    /*
     * Function: setSpeed
     * ------------------
     *  Purpose: Sets the playback speed ratio for the audio player.
     *
     *   Input:  ratio - The desired speed ratio (1.0 for normal speed).
     */
    void setSpeed(double ratio);

    /*
     * Function: setPosition
     * ---------------------
     *  Purpose: Sets the playback position in seconds.
     *
     *   Input: posInSecs - The desired playback position in seconds.
     */
    void setPosition(double posInSecs);

    /*
     * Function: setPositionRelative
     * -----------------------------
     *  Purpose: Sets the playback position relative to the current position.
     *
     *   Input:  pos - The relative position as a ratio (0.0 for the start, 1.0 for the end).
     */
    void setPositionRelative(double pos);

    /*
     * Function: start
     * ---------------
     *  Purpose: Starts audio playback.
     */
    void start();

    /*
     * Function: stop
     * --------------
     *  Purpose: Stops audio playback.
     */
    void stop();

    /*
     * Function: getPositionRelative
     * -----------------------------
     *  Purpose: Gets the current playback position as a relative ratio.
     *
     *   Output: Returns the current playback position as a ratio (0.0 to 1.0).
     */
    double getPositionRelative();

private:
    // Manages audio format handling and decoding
    AudioFormatManager& formatManager;

    // Responsible for reading audio data from a file
    std::unique_ptr<AudioFormatReaderSource> readerSource;

    // Provides transport control for audio playback
    AudioTransportSource transportSource;

    // Applies resampling to the audio source (optional)
    // Parameters:
    //             sourceToResample - The source to resample (in this case, the transport source)
    //             deleteSourceWhenDone - Whether to delete the source when done (false in this case)
    //             numberOfChannels - Number of audio channels (2 in this case, stereo)
    ResamplingAudioSource resampleSource{&transportSource, false, 2};

};
