package com.cstudioss.fpsgame;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("MyEngine");
    }

    private TextView statusText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        nativeInit();

        TextView tv = findViewById(R.id.sample_text);
        tv.setText("CStudios FPS Game");

        statusText = findViewById(R.id.status_text);
        
        Button shootButton = findViewById(R.id.shoot_button);
        shootButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nativeShoot();
                updateStatus();
            }
        });

        updateStatus();
    }

    private void updateStatus() {
        int ammo = nativeGetAmmo();
        int health = nativeGetHealth();
        statusText.setText("Ammo: " + ammo + " | Health: " + health);
    }

    public native void nativeInit();
    public native void nativeShoot();
    public native int nativeGetAmmo();
    public native int nativeGetHealth();
}
