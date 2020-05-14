/*
  ==============================================================================

    Oscillator.cpp
    Created: 13 May 2020 12:31:18am
    Author:  marco

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthFrameworkAudioProcessor& p) :
    processor(p)
{
    setSize(200, 200);

    oscMenu.addItem("Square", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Sine", 3);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);

    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype", oscMenu);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
    Rectangle<int> titleArea(0, 10, getWidth(), 20);

    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Oscillator", titleArea, Justification::centredTop);


    Rectangle<float> area(25, 25, 150, 150);

    g.setColour(Colours::grey);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Oscillator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    Rectangle<int> area = getLocalBounds().reduced(40);

    oscMenu.setBounds(area.removeFromTop(20));
}

void Oscillator::comboBoxChanged(ComboBox* box)
{

}
