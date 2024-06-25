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
    File name: Main.cpp
    Purpose: The Main.cpp file contains the basic startup code for the “OTO Decks”  JUCE application implementation.
 
    Adapted from: OtoDecks_start_topic_10 2
    Source: King, M. (2020, March 14). Dr [Lecturer]. Coursera. https://www.coursera.org/learn/uol-object-oriented-programming/supplement/Xc3xH/10-002-starter-code-for-topic-10

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

//==============================================================================
/*
 * Class: OtoDecksApplication
 * --------------------------
 *  Purpose: Represents the main application class for the OtoDecks application.
 *           Responsible for managing the application's lifecycle and GUI.
 */
class OtoDecksApplication  : public JUCEApplication
{
public:
    //==============================================================================
    /*
     * Constructor: OtoDecksApplication
     * -------------------------------
     *  Purpose: Initializes the OtoDecks application.
     */
    OtoDecksApplication() {}

    /*
     * Function: getApplicationName
     * ----------------------------
     *  Purpose: Gets the name of the application.
     *
     *   Output: The name of the application as a String.
     */
    const String getApplicationName() override       { return ProjectInfo::projectName; }

    /*
     * Function: getApplicationVersion
     * -------------------------------
     *  Purpose: Gets the version string of the application.
     *
     *   Output: The version string of the application as a String.
     */
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }

    /*
     * Function: moreThanOneInstanceAllowed
     * -------------------------------------
     *  Purpose: Checks if more than one instance of the application is allowed.
     *
     *   Output: Boolean indicating if more than one instance is allowed.
     */
    bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    
    /*
     * Function: initialise
     * --------------------
     *  Purpose: Initializes the application.
     *
     *   Input: commandLine - The command line arguments passed to the application.
     */
    void initialise (const String& commandLine) override
    {
        mainWindow.reset (new MainWindow (getApplicationName()));
    }
    
    /*
     * Function: shutdown
     * ------------------
     *  Purpose: Shuts down the application.
     */
    void shutdown() override
    {
        mainWindow = nullptr;
    }

    //==============================================================================
    
    /*
     * Function: systemRequestedQuit
     * -----------------------------
     *  Purpose: Handles the system request to quit the application.
     */
    void systemRequestedQuit() override
    {
        quit();
    }
    
    /*
     * Function: anotherInstanceStarted
     * ---------------------------------
     *  Purpose: Handles the start of another instance of the application.
     *
     *   Input: commandLine - The command line arguments passed to the new instance.
     */
    void anotherInstanceStarted (const String& commandLine) override
    {}

    //==============================================================================
    /*
     * Class: MainWindow
     * -----------------
     *  Purpose: Represents the main application window that hosts the application's GUI.
     *           Manages the window's appearance and interactions.
     *
     *   Inherits From: DocumentWindow - A JUCE class for creating document-style windows.
     */
    class MainWindow    : public DocumentWindow
    {
        /*
         * Constructor: MainWindow
         * -------------------------
         *  Purpose: Initialize the main application window.
         *
         *   Input:  name - The name of the window.
         */
         public: MainWindow (String name)  : DocumentWindow (name,
                                                             Desktop::getInstance().getDefaultLookAndFeel().findColour (ResizableWindow::backgroundColourId),
                                                             DocumentWindow::allButtons)
            {
                setUsingNativeTitleBar (true);
                setContentOwned (new MainComponent(), true);
                #if JUCE_IOS || JUCE_ANDROID
                setFullScreen (true);
                #else
                setResizable (true, true);
                centreWithSize (getWidth(), getHeight());
                #endif
               setVisible (true);
            }
        
        /*
         * Function: closeButtonPressed
         * -----------------------------
         *  Purpose: Handles the user pressing the close button on the window.
         */

        void closeButtonPressed() override
        {

            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (OtoDecksApplication)

