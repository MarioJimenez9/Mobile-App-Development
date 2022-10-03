package net.ivanvega.mirollera

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    lateinit var boton: Button
    lateinit var lbl: TextView
    lateinit var img: ImageView
    lateinit var imq2: ImageView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.layout_roller)


        lbl = findViewById(R.id.lblSaludo)
        boton = findViewById(R.id.btnRoller)
        img = findViewById(R.id.imgRoller)
        imq2 = findViewById(R.id.imgRoller2)

        img.setImageDrawable(resources.getDrawable(R.drawable.dice_6))
        imq2.setImageDrawable(resources.getDrawable(R.drawable.dice_6))

        boton.setOnClickListener {
            val id1 = diceRoller()
            val id2 = diceRoller()
            val d1 = getRandomDiceImage(id1)
            val d2 = getRandomDiceImage(id2)
            Toast.makeText(
                applicationContext,
                "Boton presionado aleatorio\n Dado 1: " + id1
                + "\nDado 2: " + id2,
                Toast.LENGTH_LONG
            ).show()
            img.setImageResource(d1)
            imq2.setImageResource(d2)
            lbl.text = (id1 + id2).toString()

        }
    }
    private fun getRandomDiceImage(al: Int) : Int {
        val idImagenAl = when (al){
            1 -> R.drawable.dice_1
            2 -> R.drawable.dice_2
            3 -> R.drawable.dice_3
            4 -> R.drawable.dice_4
            5 -> R.drawable.dice_5
            6 -> R.drawable.dice_6
            else -> R.drawable.empty_dice
        }
        return idImagenAl;
    }
    private fun diceRoller() : Int{
        return (1..6).random()
    }
}