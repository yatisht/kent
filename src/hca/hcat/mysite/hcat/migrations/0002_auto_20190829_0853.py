# Generated by Django 2.1 on 2019-08-29 08:53

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('hcat', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='project',
            name='wrangler',
            field=models.ForeignKey(default=None, null=True, on_delete=django.db.models.deletion.SET_NULL, related_name='wrangler', to='hcat.Contributor'),
        ),
        migrations.AlterField(
            model_name='contributor',
            name='project_role',
            field=models.CharField(default='contributor', max_length=100),
        ),
        migrations.AlterField(
            model_name='grant',
            name='funded_contributors',
            field=models.ManyToManyField(to='hcat.Contributor'),
        ),
        migrations.AlterField(
            model_name='grant',
            name='funded_labs',
            field=models.ManyToManyField(to='hcat.Lab'),
        ),
        migrations.AlterField(
            model_name='grant',
            name='funded_projects',
            field=models.ManyToManyField(to='hcat.Project'),
        ),
        migrations.AlterField(
            model_name='grant',
            name='funder',
            field=models.ForeignKey(default=None, null=True, on_delete=django.db.models.deletion.SET_NULL, to='hcat.Funder'),
        ),
    ]