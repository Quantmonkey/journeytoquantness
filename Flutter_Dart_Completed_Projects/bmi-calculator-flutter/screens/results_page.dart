import 'package:bmi_calculator/components/ReusableCard.dart';
import 'package:bmi_calculator/components/constants.dart';
import 'package:flutter/material.dart';
import '../components/constants.dart';
import '../components/ReusableCard.dart';
import 'input_page.dart';

class ResultsPage extends StatelessWidget {

	ResultsPage({@required this.bmiResult,
		           @required this.resultText,
		           @required this.interpretation});

	final String bmiResult;
	final String resultText;
	final String interpretation;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
	    appBar: AppBar(
		    title: Text('BMI CALCULATOR'),
	    ),
	    body: Column(
		    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
		    crossAxisAlignment: CrossAxisAlignment.stretch,
		    children: <Widget>[
		    	Expanded(
				    child: Container(
					    padding: EdgeInsets.all(15.0),
					    alignment: Alignment.bottomLeft,
					    child: Text(
						    'Your Results',
						    style: kTitleTextStyle,
					    ),
				    ),
			    ),
			    Expanded(
				    flex: 5,
				    child: ReusableCard(
					    colour: kActiveReusableCardColor,
					    cardChild: Column(
						    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
						    crossAxisAlignment: CrossAxisAlignment.center,
						    children: <Widget>[
									Text(
										bmiResult,
										style: kResultTextStyle,
									),
							    Text(
								    resultText,
								    style: kBMITextStyle,
							    ),
							    Text(
								    interpretation,
								    style: kBodyTextStyle,
							    ),
						    ],
					    ),
				    )
			    ),
			    Expanded(
				    child: BottomButton(
					    buttonTitle: 'RECALCULATE',
					    onPressed: () {
						    Navigator.pop(
							    context
						    );
					    },
				    ),
			    )
		    ],
	    ),
    );
  }
}
