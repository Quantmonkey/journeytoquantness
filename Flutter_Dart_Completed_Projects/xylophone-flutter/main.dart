import 'package:flutter/material.dart';
import 'package:audioplayers/audio_cache.dart';

void main() => runApp(XylophoneApp());

class XylophoneApp extends StatelessWidget {
  void playSound(int noteNum) {
    final player =
        AudioCache(); //onPressed has a player from class AudioCache()
    player.play('note$noteNum.wav');
  }

  Expanded buildKey({int playSoundNo, Color colorChoice}) {
    return Expanded(
      child: FlatButton(
        color: colorChoice,
        onPressed: () {
          playSound(playSoundNo);
        },
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.black,
        body: SafeArea(
          child: Center(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.stretch,
              children: <Widget>[
                buildKey(playSoundNo: 1, colorChoice: Colors.red),
                buildKey(playSoundNo: 2, colorChoice: Colors.orange),
                buildKey(playSoundNo: 3, colorChoice: Colors.yellow),
                buildKey(playSoundNo: 4, colorChoice: Colors.green),
                buildKey(playSoundNo: 5, colorChoice: Colors.teal),
                buildKey(playSoundNo: 6, colorChoice: Colors.blue),
                buildKey(playSoundNo: 7, colorChoice: Colors.purple),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
