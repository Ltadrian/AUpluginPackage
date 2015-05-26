/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GainPluginAudioProcessorEditor::GainPluginAudioProcessorEditor (GainPluginAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 1, 0.1);
    slider->setSliderStyle (Slider::Rotary);
    slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    slider->setColour (Slider::thumbColourId, Colour (0xfff2f2ff));
    slider->setColour (Slider::trackColourId, Colour (0x7fffffff));
    slider->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    slider->setColour (Slider::textBoxBackgroundColourId, Colours::white);
    slider->setColour (Slider::textBoxHighlightColourId, Colour (0x40ffffff));
    slider->setColour (Slider::textBoxOutlineColourId, Colour (0xb2ffffff));
    slider->addListener (this);

    addAndMakeVisible (gainLabel = new Label ("new label",
                                              TRANS("GAIN")));
    gainLabel->setFont (Font ("Gabriola", 61.20f, Font::plain));
    gainLabel->setJustificationType (Justification::centredLeft);
    gainLabel->setEditable (false, false, false);
    gainLabel->setColour (TextEditor::textColourId, Colours::black);
    gainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 300);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    //[/Constructor]
}

GainPluginAudioProcessorEditor::~GainPluginAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    gainLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GainPluginAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffc00000));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GainPluginAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    slider->setBounds (40, 88, 184, 112);
    gainLabel->setBounds (72, 0, 208, 136);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GainPluginAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    GainPluginAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        ourProcessor->setParameterNotifyingHost(GainPluginAudioProcessor::Gain, (float) slider->getValue());
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GainPluginAudioProcessorEditor::timerCallback()
{
    GainPluginAudioProcessor* ourProcessor = getProcessor();
    slider->setValue(ourProcessor->getParameter(GainPluginAudioProcessor::Gain), dontSendNotification);

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GainPluginAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="GainPluginAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="400" initialHeight="300">
  <BACKGROUND backgroundColour="ffc00000"/>
  <SLIDER name="new slider" id="f9e0cbba5210737b" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="40 88 184 112" bkgcol="ffffff" thumbcol="fff2f2ff"
          trackcol="7fffffff" rotarysliderfill="7fffffff" rotaryslideroutline="66ffffff"
          textboxbkgd="ffffffff" textboxhighlight="40ffffff" textboxoutline="b2ffffff"
          min="0" max="1" int="0.10000000000000000555" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="dc534aaf94251e89" memberName="gainLabel"
         virtualName="" explicitFocusOrder="0" pos="72 0 208 136" edTextCol="ff000000"
         edBkgCol="0" labelText="GAIN" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Gabriola" fontsize="61.200000000000002842"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
