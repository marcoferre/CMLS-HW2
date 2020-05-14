/*
  ==============================================================================

    SynthSound.h
    Created: 10 May 2020 12:19:44am
    Author:  marco

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public SynthesiserSound
{
    bool appliesToNote(int /*midiNoteNumber*/)
    {
        return true;
    }
    bool appliesToChannel(int /*midiChannel*/)
    {
        return true;
    }
};