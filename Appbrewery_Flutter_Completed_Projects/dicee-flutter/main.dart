import 'package:flutter/material.dart';
import 'dart:math';

void main() {
  return runApp(
	MaterialApp(
	  home: Scaffold(
		backgroundColor: Colors.red,
		appBar: AppBar(
		  title: Text('Dicee'),
		  backgroundColor: Colors.red,
		),
		body: DicePage(),
	  ),
	),
  );
}

class DicePage extends StatefulWidget {
  @override
  _DicePageState createState() => _DicePageState();
}

// State is now mutable
class _DicePageState extends State<DicePage> {

  int leftDiceNumber = 1; //initialisation
  int rightDiceNumber = 1;



  @override
  Widget build(BuildContext context) {

}
