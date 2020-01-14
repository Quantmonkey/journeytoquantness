import 'package:flutter/material.dart';
import 'dart:math';


void main() => runApp(
      MaterialApp(
        home: BallPage(),
      ),
    );

class BallPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Ball();
  }
}

class Ball extends StatefulWidget {
  @override
  _BallState createState() => _BallState();
}

class _BallState extends State<Ball> {

  int magicBallNo = 1;

  // Returns nothing, updates two int variables used in dice
  void updateMagicNum () {
    setState(() {
      magicBallNo = Random().nextInt(5) + 1;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Row(
        children: <Widget>[
          Expanded(
            child: FlatButton(
              onPressed: () {
                updateMagicNum();
              },
              child: Image.asset('images/ball$magicBallNo.png'),
            ),
          ),
        ],
      ),
    );
  }
  }
