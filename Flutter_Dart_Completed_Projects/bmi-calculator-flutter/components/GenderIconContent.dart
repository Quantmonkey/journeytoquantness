import 'package:flutter/material.dart';
import 'constants.dart';

class GenderIconContent extends StatelessWidget {
	GenderIconContent({@required this.genderIcon, @required this.sex});

	final IconData genderIcon;
	final String sex;

	@override
	Widget build(BuildContext context) {
		return Column(
			mainAxisAlignment: MainAxisAlignment.center,
			children: <Widget>[
				Icon(
					genderIcon,
					size: 80.0,
				),
				SizedBox(
					height: 15.0,
				),
				Text(
					sex,
					style: kTextStyling,
				),
			],
		);
	}
}