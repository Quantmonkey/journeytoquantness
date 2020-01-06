import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import '../components/ReusableCard.dart';
import '../components/GenderIconContent.dart';
import '../components/constants.dart';
import 'results_page.dart';
import 'package:bmi_calculator/calculator_brain.dart';

enum Gender {male, female}

class InputPage extends StatefulWidget {
	@override
	_InputPageState createState() => _InputPageState();
}

class _InputPageState extends State<InputPage> {

	@override
	Widget build(BuildContext context) {
		return Scaffold(
			appBar: AppBar(
				title: Text('BMI CALCULATOR'),
			),
			body: Column(
				children: <Widget>[
					SelectGenderRow(),
					DragHeightRow(),
					SelectWeightAndAgeRow(),
					BottomButton(
							buttonTitle: 'CALCULATE',
							onPressed: () {
								CalculatorBrain calc =
									CalculatorBrain(height: _DragHeightRow.height,
																	weight: _SelectWeightAndAgeRow.weight);
							Navigator.push(
								context,
								MaterialPageRoute(
									builder: (context) {
										return ResultsPage(
											bmiResult: calc.calculateBMI(),
											resultText: calc.getResult(),
											interpretation: calc.getInterpretation(),
										);
									},
								),
							);
						},
					),
				],
			),
		);
	}
}

class BottomButton extends StatelessWidget {

	BottomButton ({@required this.onPressed, @required this.buttonTitle});

	final Function onPressed;
	final String buttonTitle;

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
    	onTap: onPressed,
      child: Container(
      	child: Center(
      	  child: Text(buttonTitle,
    	  style: kLargeButtonStyling,
    	  ),
      	),
      	color: kBottomContainerColor,
      	margin: EdgeInsets.only(top: 10.0),
    	  width: double.infinity,
      	height: kBottomContainerHeight,
      ),
    );
  }
}

class SelectGenderRow extends StatefulWidget {
	@override
	_SelectGenderRow createState() => _SelectGenderRow();
}

class _SelectGenderRow extends State<SelectGenderRow> {

	Gender selectedGender;

	@override
	Widget build(BuildContext context) {
		return Expanded(
			child: Row(
				children: <Widget>[
					Expanded(
						child: ReusableCard(
							onPress: () {
								setState(() {
								  selectedGender = Gender.male;
								});
							},
							colour: selectedGender == Gender.male
								? kActiveReusableCardColor
								: kInactiveReusableCardColor,
							cardChild: GenderIconContent(
								genderIcon: FontAwesomeIcons.mars,
								sex: 'Male',
							),
						),
					),
					Expanded(
						child: ReusableCard(
							onPress: () {
								setState(() {
									selectedGender = Gender.female;
								});
							},
							colour: selectedGender == Gender.female
								? kActiveReusableCardColor
								: kInactiveReusableCardColor,
							cardChild: GenderIconContent(
								genderIcon: FontAwesomeIcons.venus,
								sex: 'Female',
							),
						),
					),
				],
			),
		);
	}
}

class DragHeightRow extends StatefulWidget {
	@override
	_DragHeightRow createState() => _DragHeightRow();
}

class _DragHeightRow extends State<DragHeightRow> {
	 static int height = 180;

	@override
	Widget build(BuildContext context) {
		return Expanded(
			child: Row(
				children: <Widget>[
					Expanded(
						child: ReusableCard(
							colour: kActiveReusableCardColor,
							cardChild: Column(
								mainAxisAlignment: MainAxisAlignment.center,
								children: <Widget>[
									Text(
										'HEIGHT',
										style: kTextStyling,
									),
									Row(
										mainAxisAlignment: MainAxisAlignment.center,
										crossAxisAlignment: CrossAxisAlignment.baseline,
										textBaseline: TextBaseline.alphabetic,
										children: <Widget>[
											Text(
												height.toString(),
												style: kNumberStyling,
											),
											Text(
												'cm',
												style: kTextStyling,
											),
										],
									),
									Slider(
										value: height.toDouble(),
										min: 120,
										max: 220,
										activeColor: Color(0xFFEB1555),
										inactiveColor: Color(0xFF8D8E98),
										onChanged: (double newValue) {
											setState(() {
												height = newValue.toInt();
											});
										},
									),
								],
							),
						),
					),
				],
			),
		);
	}
}

class SelectWeightAndAgeRow extends StatefulWidget {
	@override
	_SelectWeightAndAgeRow createState() => _SelectWeightAndAgeRow();
}

class _SelectWeightAndAgeRow extends State<SelectWeightAndAgeRow> {

	static int weight = 80;
	int age = 24;

	@override
	Widget build(BuildContext context) {
		return Expanded(
			child: Row(
				children: <Widget>[
					Expanded(
						child: ReusableCard(
							colour: kActiveReusableCardColor,
							cardChild: Column(
								mainAxisAlignment: MainAxisAlignment.center,
								children: <Widget>[
									Text(
										'WEIGHT',
										style: kTextStyling,
									),
									Text(
										weight.toString(),
										style: kNumberStyling,
									),
									Row(
										mainAxisAlignment: MainAxisAlignment.center,
										children: <Widget>[
											RoundIconButton(
												icon: FontAwesomeIcons.minus,
												onPress: () {
													setState(() {
														weight--;
													});
												},
											),
											SizedBox(
												width: 10,
											),
											RoundIconButton(
												icon: FontAwesomeIcons.plus,
												onPress: () {
													setState(() {
														weight++;
													});
												},
											),
										],
									)
								],
							),
						),
					),
					Expanded(
						child: ReusableCard(
							colour: kActiveReusableCardColor,
							cardChild: Column(
								mainAxisAlignment: MainAxisAlignment.center,
								children: <Widget>[
									Text(
										'AGE',
										style: kTextStyling,
									),
									Text(
										age.toString(),
										style: kNumberStyling,
									),
									Row(
										mainAxisAlignment: MainAxisAlignment.center,
										children: <Widget>[
											RoundIconButton(
												icon: FontAwesomeIcons.minus,
												onPress: () {
													setState(() {
														age--;
													});
												},
											),
											SizedBox(
												width: 10,
											),
											RoundIconButton(
												icon: FontAwesomeIcons.plus,
												onPress: () {
													setState(() {
														age++;
													});
												},
											),
										],
									)
								],
							),
						),
					),
				],
			),
		);
	}
}

class RoundIconButton extends StatelessWidget {

	RoundIconButton({this.icon, this.onPress});

	final IconData icon;
	final Function onPress;

	@override
  Widget build(BuildContext context) {
    return RawMaterialButton(
	    child: Icon(icon),
	    onPressed: onPress,
	    elevation: 6.0,
	    constraints: BoxConstraints.tightFor(
		    width: 56.0,
		    height: 56.0,
	    ),
	    shape: CircleBorder(),
	    fillColor: Color(0xFF4C4F5E),
    );
  }
}

